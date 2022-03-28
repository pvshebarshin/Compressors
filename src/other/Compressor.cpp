#include "Compressor.h"

void Compressor::findCompressionRatio(const string& inputFile, string cFile, string& experiment_result) const noexcept
{
    if (this->checkFile(&inputFile) && this->checkFile(&cFile))
    {
        ifstream input_file_stream1;
        input_file_stream1.open(inputFile, ios::binary);
        string input1((istreambuf_iterator<char>(input_file_stream1)),
                      (istreambuf_iterator<char>()));

        ifstream input_file_stream2;
        input_file_stream2.open(cFile, ios::binary);
        string input2((istreambuf_iterator<char>(input_file_stream2)),
                      (istreambuf_iterator<char>()));

        int index = 0;
        while (cFile[index] != '.')
            ++index;

        string type;
        while (index != cFile.size())
        {
            type += cFile[index];
            ++index;
        }

        double ratio = (double) input2.size() / (double) input1.size();
        experiment_result += "Коэффициен сжатия для " + type + " - " + to_string(ratio) + '\n';
        input_file_stream1.close();
        input_file_stream2.close();
    }
}

void Compressor::findEntropy(const string* fileName, string& experiment_result) const noexcept
{
    if (this->checkFile(&*fileName))
    {
        ifstream input_file_stream;
        input_file_stream.open(*fileName, ios::binary);
        map<unsigned char, unsigned long long int> count;
        string input((istreambuf_iterator<char>(input_file_stream)),
                     (istreambuf_iterator<char>()));

        support->get_counts(&input, count);

        double res = 0;
        uint64_t count_of_symbols = 0;
        for (auto it = count.begin(); it != count.end(); ++it)
            count_of_symbols += it->second;

        for (auto it = count.begin(); it != count.end(); ++it)
            res += (double) it->second / (double) count_of_symbols
                   * log2((double) it->second / (double) count_of_symbols);
        res = -res;
        experiment_result += "Энтропия файла - " + to_string(res) + '\n';
        experiment_result += "Символ:\tКол-во в файле:\n";

        map<unsigned char, uint64_t>::iterator it;
        for (int i = 0; i < 256; ++i)
        {
            it = count.find((unsigned char) i);
            if (it != count.end()) {
                experiment_result += to_string(it->first) + "\t"
                                     + to_string(it->second) + '\n';
            } else {
                experiment_result += to_string(i) + "\t" + '0' + '\n';
            }
        }
        input_file_stream.close();
    }
}

bool Compressor::checkFile(const string* filePath) const noexcept
{
    ifstream file;
    file.open(*filePath);
    if (file.is_open()) {
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}

Compressor::~Compressor() noexcept
{
    delete this->support;
    delete this->huffman;
    delete this->shannonFano;
    delete this->lz77;
}

Compressor::Compressor() noexcept
{
    this->support = new Support();
    this->huffman = new Huffman();
    this->shannonFano = new ShannonFano();
    this->lz77 = new LZ77();
}

void Compressor::compress_SH_F(const string& inFileName, const string& outFileName)
{
    if (this->checkFile(&inFileName)) {
        ifstream input_file_stream;
        input_file_stream.open(inFileName, ios::binary);
        ofstream output_file_stream;
        output_file_stream.open(outFileName, ios::binary);

        string output;
        string input((istreambuf_iterator<char>(input_file_stream)),
                     (istreambuf_iterator<char>()));

        //мап из сивола и его частоты
        map<unsigned char, uint64_t> counts;
        support->get_counts(&input, counts);

        //Создание вектора для сортировки значений мапа
        vector<pair<uint64_t, unsigned char>> counts_vec;
        for (auto it = counts.begin(); it != counts.end(); ++it)
            counts_vec.push_back(make_pair(it->second, it->first));

        //Сортируем вектор по убыванию
        sort(counts_vec.begin(), counts_vec.end());
        reverse(begin(counts_vec), end(counts_vec));

        //Создание кода Шенона Фано
        for (auto it = counts_vec.begin(); it != counts_vec.end(); ++it)
            this->shannonFano->addChance(it->first);
        this->shannonFano->build();

        string compress;

        map<unsigned char, string> _map;
        support->makeMapForEncode(_map, &counts_vec, &counts, &this->shannonFano);
        support->writeMapToString(&_map, output);


        for (char i : input)
            compress += _map[i];

        //запись кол-ва битов исходного файла
        output += to_string(compress.length()) + ">=";

        support->writeCodeInString(compress, output);

        output_file_stream << output;

        input_file_stream.close();
        output_file_stream.close();
        refreshSH_F();
    }
}

void Compressor::decompress_SHF_or_H(const string& inFileName, const string& outFileName)
{
    if (this->checkFile(&inFileName)) {
        ifstream input_file_stream;
        input_file_stream.open(inFileName, ios::binary);
        ofstream output_file_stream;
        output_file_stream.open(outFileName, ios::binary);

        string temp;
        string output;
        string input((istreambuf_iterator<char>(input_file_stream)),
                     (istreambuf_iterator<char>()));

        int dictionary_count;
        uint64_t index = 0;

        while (input[index] != '>')
        {
            temp += input[index];
            ++index;
        }
        index += 2;
        dictionary_count = stoi(temp);

        int need_index;

        support->getSubstrings(&input, ">=<<", need_index);

        map<string, unsigned char> _map;
        unsigned char temp_char;
        string temp_string = input.substr(index, need_index);
        string delimiter = ">=";
        string token;
        index += temp_string.length() - 1;

        support->makeMapForDecode(temp_string, temp, temp_char, _map);

        uint64_t bit_count;
        temp_string = "";
        while (input[index] != '>')
        {
            temp_string += input[index];
            ++index;
        }
        index += 2;

        bit_count = stoull(temp_string);

        for (auto it = _map.begin(); it != _map.end(); ++it)
            temp_string = it->second;

        string code = input.substr(index);
        string encode;
        support->getStringForEncode(encode, &code, &bit_count);

        support->getEncodedString(temp, output, encode, &_map);
        output_file_stream << output;

        input_file_stream.close();
        output_file_stream.close();
    }
}

void Compressor::compress_H(const string& inFileName, const string& outFileName)
{
    if (this->checkFile(&inFileName)) {
        ifstream input_file_stream;
        input_file_stream.open(inFileName, ios::binary);
        ofstream output_file_stream;
        output_file_stream.open(outFileName, ios::binary);

        string output;
        string input((istreambuf_iterator<char>(input_file_stream)),
                     (istreambuf_iterator<char>()));

        //мап из сивола и его частоты
        map<unsigned char, uint64_t> counts;
        support->get_counts(&input, counts);

        //Создание вектора для сортировки значений мапа
        vector<pair<uint64_t, unsigned char>> counts_vec;
        for (auto it = counts.begin(); it != counts.end(); ++it)
            counts_vec.push_back(make_pair(it->second, it->first));

        //Сортируем вектор по убыванию
        sort(counts_vec.begin(), counts_vec.end());
        reverse(begin(counts_vec), end(counts_vec));

        //Создание кода Хафмена
        for (auto it = counts_vec.begin(); it != counts_vec.end(); ++it)
            this->huffman->addChance(it->first);
        this->huffman->build();

        string compress;

        map<unsigned char, string> _map;
        support->makeMapForEncode(_map, &counts_vec, &counts, &this->huffman);
        support->writeMapToString(&_map, output);

        for (char i : input)
            compress += _map[i];

        //запись кол-ва битов исходного файла
        output += to_string(compress.length()) + ">=";

        support->writeCodeInString(compress, output);

        output_file_stream << output;

        input_file_stream.close();
        output_file_stream.close();
        refreshH();
    }
}

void Compressor::compress_LZ77(const string& inFileName, const string& outFileName,
                               int Buffer_Story_Length, int Buffer_Pre_Length)
{
    if (this->checkFile(&inFileName)) {
        ifstream input_file_stream;
        input_file_stream.open(inFileName, ios::binary);

        ofstream output_file_stream;
        output_file_stream.open(outFileName, ios::binary);
        string input((istreambuf_iterator<char>(input_file_stream)),
                     (istreambuf_iterator<char>()));

        vector<LZ77::Node *> result_nodes;
        this->lz77->encode(input, result_nodes, Buffer_Story_Length, Buffer_Pre_Length);

        string output = to_string(result_nodes.size()) + ' ';
        for (int i = 0; i < result_nodes.size(); ++i)
            output += to_string(result_nodes[i]->offset) + " "
                      + to_string(result_nodes[i]->length) + " "
                      + result_nodes[i]->ch + " ";

        output_file_stream << output;
        input_file_stream.close();
        output_file_stream.close();
        result_nodes.clear();
        result_nodes.shrink_to_fit();
        refreshLZ77();
    }
}

void Compressor::decompress_LZ77(const string& inFileName, const string& outFileName)
{
    if (this->checkFile(&inFileName)) {
        ifstream input_file_stream;
        input_file_stream.open(inFileName, ios::binary);

        ofstream output_file_stream;
        output_file_stream.open(outFileName, ios::binary);

        string output = this->lz77->decode(&input_file_stream);
        output_file_stream << output;
        input_file_stream.close();
        output_file_stream.close();
    }
}

void Compressor::refreshH() noexcept
{
    delete this->huffman;
    this->huffman = new Huffman();
}

void Compressor::refreshSH_F() noexcept
{
    delete this->shannonFano;
    this->shannonFano = new ShannonFano();
}

void Compressor::compress_LZ77_H(const string& inFileName, const string& outFileName1, const string& outFileName2,
                                 int Buffer_Story_Length, int Buffer_Pre_Length)
{
    if (this->checkFile(&inFileName)) {
        this->compress_LZ77(inFileName, outFileName1, Buffer_Story_Length, Buffer_Pre_Length);
        this->compress_H(outFileName1, outFileName2);
    }
}

void Compressor::decompress_LZ77_H_or_LZ77_SH_F(const string& inFileName, const string& outFileName1,
                                                const string& outFileName2)
{
    if (this->checkFile(&inFileName)) {
        this->decompress_SHF_or_H(inFileName, outFileName1);
        this->decompress_LZ77(outFileName1, outFileName2);
    }
}

void Compressor::compress_LZ77_SH_F(const string& inFileName, const string& outFileName1, const string& outFileName2,
                                    int Buffer_Story_Length, int Buffer_Pre_Length)
{
    if (this->checkFile(&inFileName))
    {
        this->compress_LZ77(inFileName, outFileName1, Buffer_Story_Length, Buffer_Pre_Length);
        this->compress_SH_F(outFileName1, outFileName2);
    }
}

void Compressor::refreshLZ77() noexcept
{
    delete this->lz77;
    this->lz77 = new LZ77();
}
