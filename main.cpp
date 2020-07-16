#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <bitset>
#include <chrono>
#include "ShannonFano.cpp"
#include "LZ77.cpp"
#include <thread>
#include "LZW.cpp"
#include "Huffman.cpp"

//Создание вспомогательного массива для
//алгоритма Кнута-Мориса-Пратта
int* pi(string str);

//Поиск нулевого индекса первого вхождения строки в строку
//по алгоритму Кнута-Мориса_Пратта
void getSubstrings(string* source, string substring, int& res);

//Метод сжатия по алгоритму Шеннона_Фано
void compress_SH_F(string& inFileName, string& outFileName);

//Метод распаковки по алгоритму Шеннона_Фано
void decompress_SHF_or_H(string& inFileName, string& outFileName);

//Метод сжатия по алгоритму Хафмена
void compress_H(string& inFileName, string& outFileName);

//Метод сжатия по алгоритму LZ77
//Размер скользящего окна 5 Кб, размер словаря 4 Кб архивированный
void compress_LZ77(string& inFileName, string& outFileName,
                    int Buffer_Story_Length, int Buffer_Pre_Length);

//Метод распаковки по алгоритму LZ77
void decompress_LZ77(string& inFileName, string& outFileName);

//Проверка существования файла
bool checkFile(string* filePath);

//Нахождение частот всеъ символов
void get_counts(string* data, map<unsigned char, unsigned long long int>& count);

//Создание вспомогательного map для кодирования Шенона-Фано
void makeMapForEncode(map<unsigned char, string>& _map,
        vector<pair<unsigned long long int, unsigned char>>* counts_vec,
             map<unsigned char, unsigned long long int>* counts,
             ShannonFano* *shf);

//Создание вспомогательного map для кодирования Хафмена
void makeMapForEncode(map<unsigned char, string>& _map,
                      vector<pair<unsigned long long int, unsigned char>>* counts_vec,
                      map<unsigned char, unsigned long long int>* counts,
                      Huffman* *huff);

//Создание вспомогательного map для декодирования
void makeMapForDecode(string& temp, string& temp_string, unsigned char& temp_char,
                      map<string, unsigned char>& _map);

//Запись map в строку
void writeMapToString(map<unsigned char, string>* _map, string& output);

//Запись битов кода в строку
void writeCodeInString(string& compress, string& output);

//Декодирование строки из 0 и 1
void getEncodedString(string& temp, string& output,
        string& encode,map<string, unsigned char>* _map);

//Получить строчку для декодирования из 0 и 1
void getStringForEncode(string& encode, string* code,
                        unsigned long long int* bit_count);

//Поиск энтропии файла
void findEntropy(string* fileName, string& experiment_result);

//Поиск коэффициентов сжатия
void findCompressionRatio(const string& inputFile, string cFile, string& experiment_result);

//Посчитать всю информацию для одного файла
void makeSingleExperement(string inputFileName, string compress1, string compress2,
                          string compress3, string compress4, string compress5, string res1, string res2,
                          string res3, string res4, string res5);

void printResults(const string& fileName, string& experiment_result);

int main()
{
    thread thread1(&makeSingleExperement, "DATA/1.txt", "1.shan", "1.lz775",
                      "1.lz7710", "1.lz7720", "1.huff", "RESULTSHF/1.txt",
                      "RESULTLZ775/1.txt","RESULTLZ7710/1.txt",
                      "RESULTLZ7720/1.txt", "RESULTH/1.txt");

    thread thread2(&makeSingleExperement, "DATA/2.docx", "2.shan", "2.lz775",
                   "2.lz7710", "2.lz7720", "2.huff", "RESULTSHF/2.docx",
                   "RESULTLZ775/2.docx","RESULTLZ7710/2.docx",
                   "RESULTLZ7720/2.docx", "RESULTH/2.docx");

    thread thread3(&makeSingleExperement, "DATA/3.pptx", "3.shan", "3.lz775",
                   "3.lz7710", "3.lz7720", "3.huff", "RESULTSHF/3.pptx",
                   "RESULTLZ775/3.pptx","RESULTLZ7710/3.pptx",
                   "RESULTLZ7720/3.pptx", "RESULTH/3.pptx");

    thread thread4(&makeSingleExperement, "DATA/4.png", "4.shan", "4.lz775",
                   "4.lz7710", "4.lz7720", "4.huff", "RESULTSHF/4.png",
                   "RESULTLZ775/4.png","RESULTLZ7710/4.png",
                   "RESULTLZ7720/4.png", "RESULTH/4.png");

    thread thread5(&makeSingleExperement, "DATA/5.pdf", "5.shan", "5.lz775",
                   "5.lz7710", "5.lz7720", "5.huff", "RESULTSHF/5.pdf",
                   "RESULTLZ775/5.pdf","RESULTLZ7710/5.pdf",
                   "RESULTLZ7720/5.pdf", "RESULTH/5.pdf");

    thread thread6(&makeSingleExperement, "DATA/6.xlsx", "6.shan", "6.lz775",
                   "6.lz7710", "6.lz7720", "6.huff", "RESULTSHF/6.xlsx",
                   "RESULTLZ775/6.xlsx","RESULTLZ7710/6.xlsx",
                   "RESULTLZ7720/6.xlsx", "RESULTH/6.xlsx");
    thread thread7(&makeSingleExperement, "DATA/7.bmp", "7.shan", "7.lz775",
                   "7.lz7710", "7.lz7720", "7.huff", "RESULTSHF/7.bmp",
                   "RESULTLZ775/7.bmp","RESULTLZ7710/7.bmp",
                   "RESULTLZ7720/7.bmp", "RESULTH/7.bmp");

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();

    return 0;
}

void makeSingleExperement(string inputFileName, string compress1, string compress2,
        string compress3, string compress4, string compress5, string res1, string res2,
        string res3, string res4, string res5)
{
    if(checkFile(&inputFileName)){

        //Строка для вывода результатов опыта
        string experiment_result = "Эксперемент над файлом " + inputFileName + '\n';
        findEntropy(&inputFileName, experiment_result);

        chrono::steady_clock::time_point duration1;
        chrono::steady_clock::time_point duration2;
        chrono::duration<double> diff{};

        experiment_result += "\nВремя сжатия для Шенона-Фано\n";
        duration1 = chrono::steady_clock::now();
        compress_SH_F(inputFileName, compress1);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя распаковки для Шенона-Фано\n";
        duration1 = chrono::steady_clock::now();
        decompress_SHF_or_H(compress1, res1);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя сжатия для Хафмена\n";
        duration1 = chrono::steady_clock::now();
        compress_H(inputFileName, compress5);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя распаковки для Хафмена\n";
        duration1 = chrono::steady_clock::now();
        decompress_SHF_or_H(compress5, res5);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя сжатия для LZ77_5\n";
        duration1 = chrono::steady_clock::now();
        compress_LZ77(inputFileName, compress2, 4096, 1024);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя распаковки для LZ77_5\n";
        duration1 = chrono::steady_clock::now();
        decompress_LZ77(compress2, res2);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя сжатия для LZ77_10\n";
        duration1 = chrono::steady_clock::now();
        compress_LZ77(inputFileName, compress3, 8192, 2048);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя распаковки для LZ77_10\n";
        duration1 = chrono::steady_clock::now();
        decompress_LZ77(compress3, res3);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя сжатия для LZ77_20\n";
        duration1 = chrono::steady_clock::now();
        compress_LZ77(inputFileName, compress4, 16384, 4096);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя распаковки для LZ77_20\n";
        duration1 = chrono::steady_clock::now();
        decompress_LZ77(compress4, res4);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';
        experiment_result += '\n';

        findCompressionRatio(inputFileName, compress1, experiment_result);
        findCompressionRatio(inputFileName, compress2, experiment_result);
        findCompressionRatio(inputFileName, compress3, experiment_result);
        findCompressionRatio(inputFileName, compress4, experiment_result);
        findCompressionRatio(inputFileName, compress5, experiment_result);

        string number;
        for(char item : inputFileName)
            if(item >= '0' && item <= '9')
                number += item;

        printResults("output" + number + ".txt", experiment_result);
    }else{
        cout << "file " + inputFileName + " not founded\n";
    }
}

void findCompressionRatio(const string& inputFile, string cFile, string& experiment_result)
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

    double ratio = (double)input2.size() / (double)input1.size();
    experiment_result += "Коэффициен сжатия для " + type + " - " + to_string(ratio) + '\n';
    input_file_stream1.close();
    input_file_stream2.close();
}

void get_counts(string* data, map<unsigned char, unsigned long long int>& count)
{
    for (unsigned long long int i = 0; i < (*data).length(); ++i)
        ++count[(*data)[i]];
}

bool checkFile(string* filePath)
{
    ifstream file;
    file.open(*filePath);
    if (file.is_open()){
        file.close();
        return true;
    } else {
        file.close();
        return false;
    }
}

void getSubstrings(string* source, string substring, int& res)
{
    int *p = pi(substring);
    int count = 0;

    for (int i = 0; i < (*source).length(); ++i)
    {
        while (count > 0 && substring[count] != (*source)[i])
            count = p[count - 1];

        if (substring[count] == (*source)[i])
            ++count;

        if (count == substring.length())
        {
            res = i - (int) substring.length() + 1;
            delete[] p;
            return;
        }
    }
}

int* pi(string str)
{
    int *pi = new int[str.size()];
    for(int i = 0; i < str.size(); ++i)
        pi[i] = 0;

    int k = 0;

    for (int i = 1; i < str.size(); ++i)
    {
        while (k > 0 && str[i] != str[k])
            k = pi[k - 1];
        if (str[i] == str[k])
            ++k;
        pi[i] = k;
    }

    return pi;
}

void findEntropy(string* fileName, string& experiment_result)
{
    ifstream input_file_stream;
    input_file_stream.open(*fileName, ios::binary);
    map<unsigned char, unsigned long long int> count;
    string input((istreambuf_iterator<char>(input_file_stream)),
                 (istreambuf_iterator<char>()));

    get_counts(&input, count);

    double res = 0;
    unsigned long long int count_of_symbols = 0;
    for(auto it = count.begin(); it != count.end(); ++it)
        count_of_symbols += it->second;

    for(auto it = count.begin(); it != count.end(); ++it)
        res += (double)it->second / (double)count_of_symbols
                * log2((double)it->second / (double)count_of_symbols);
    res = -res;
    experiment_result += "Энтропия файла - " + to_string(res) + '\n';
    experiment_result += "Символ:\tКол-во в файле:\n";

    map<unsigned char, unsigned long long int>::iterator it;
    for(int i = 0; i < 256; ++i)
    {
        it = count.find((unsigned char)i);
        if (it != count.end()){
            experiment_result += to_string(it->first) + "\t"
                    + to_string(it->second) + '\n';
        }else{
            experiment_result += to_string(i) + "\t" + '0' + '\n';
        }
    }
    input_file_stream.close();
}

void printResults(const string& fileName, string& experiment_result)
{
    ofstream output_file_stream;
    output_file_stream.open(fileName, ios::binary);
    output_file_stream << experiment_result;
    output_file_stream.close();
}

void makeMapForEncode(map<unsigned char, string>& _map,
             vector<pair<unsigned long long int, unsigned char>>* counts_vec,
             map<unsigned char, unsigned long long int>* counts,
             ShannonFano* *shf)
{
    for(auto it = (*counts).begin(); it != (*counts).end(); ++it)
        for(int i = 0; i < (*counts_vec).size(); ++i)
            if((*counts_vec)[i].first == it->second)
                _map.insert(make_pair((*counts_vec)[i].second, (*shf)->get(i)));
}

void makeMapForEncode(map<unsigned char, string>& _map,
                      vector<pair<unsigned long long int, unsigned char>>* counts_vec,
                      map<unsigned char, unsigned long long int>* counts,
                      Huffman* *huff)
{
    for(auto it = (*counts).begin(); it != (*counts).end(); ++it)
        for(int i = 0; i < (*counts_vec).size(); ++i)
            if((*counts_vec)[i].first == it->second)
                _map.insert(make_pair((*counts_vec)[i].second, (*huff)->get(i)));
}

void getStringForEncode(string& encode, string* code,
                        unsigned long long int* bit_count)
{
    for(unsigned long long int i = 0; i < (*code).size(); ++i)
        encode += bitset<8>((*code)[i]).to_string();
    encode = encode.substr(0, *bit_count);
}

void getEncodedString(string& temp, string& output,
                      string& encode, map<string, unsigned char>* _map)
{
    temp = "";
    for(unsigned long long int i = 0; i < encode.size(); ++i)
    {
        temp += encode[i];
        if ((*_map).find(temp) != (*_map).end())
        {
            output += (*_map)[temp];
            temp = "";
        }
    }
}

void makeMapForDecode(string& temp, string& temp_string,
                      unsigned char& temp_char, map<string, unsigned char>& _map)
{
    unsigned int pos = 0;
    unsigned int help = 0;
    string delimiter = ">=";
    string token;

    vector<unsigned char> uc_vec;
    vector<string> s_vec;
    while ((pos = temp.find(delimiter)) != string::npos)
    {
        if(help % 2 == 0)
        {
            token = temp.substr(0, pos);
            temp_char = token[0];
            uc_vec.push_back(temp_char);
        } else {
            token = temp.substr(0, pos);
            temp_string = token;
            s_vec.push_back(temp_string);
        }
        ++help;
        temp.erase(0, pos + delimiter.length());
    }
    for (int i = 0; i < s_vec.size(); ++i)
        _map.insert(make_pair(s_vec[i], uc_vec[i]));
}

void writeMapToString(map<unsigned char, string>* _map, string& output)
{
    output += to_string((*_map).size()) + ">=";
    for (auto it = (*_map).begin(); it != (*_map).end(); ++it)
    {
        output += it->first;
        output += ">=" + it->second + ">=";
    }
    output += "<<";
}

void writeCodeInString(string& compress, string& output)
{
    if(compress.length() % 8 != 0)
        while (compress.length() % 8 != 0)
            compress += '0';

    stringstream ss(compress);
    bitset<8> bits;
    while (ss.good())
    {
        ss >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }
}

void compress_SH_F(string& inFileName, string& outFileName)
{
    ifstream input_file_stream;
    input_file_stream.open(inFileName, ios::binary);
    ofstream output_file_stream;
    output_file_stream.open(outFileName, ios::binary);

    string output;
    string input((istreambuf_iterator<char>(input_file_stream)),
                 (istreambuf_iterator<char>()));

    //мап из сивола и его частоты
    map<unsigned char, unsigned long long int> counts;
    get_counts(&input, counts);

    //Создание вектора для сортировки значений мапа
    vector<pair<unsigned long long int, unsigned char>> counts_vec;
    for(auto it = counts.begin(); it != counts.end(); ++it)
        counts_vec.push_back(make_pair(it->second, it->first));

    //Сортируем вектор по убыванию
    sort(counts_vec.begin(), counts_vec.end());
    reverse(begin(counts_vec), end(counts_vec));

    //Создание кода Шенона Фано
    ShannonFano* shf = new ShannonFano();
    for(auto it = counts_vec.begin(); it != counts_vec.end(); ++it)
        shf->addChance(it->first);
    shf->build();

    string compress;

    map<unsigned char, string> _map;
    makeMapForEncode(_map, &counts_vec, &counts, &shf);
    writeMapToString(&_map, output);


    for(int i = 0; i < input.size(); ++i)
        compress += _map[input[i]];

    //запись кол-ва битов исходного файла
    output += to_string(compress.length()) + ">=";

    writeCodeInString(compress, output);

    output_file_stream << output;

    input_file_stream.close();
    output_file_stream.close();
    delete shf;
}

void decompress_SHF_or_H(string& inFileName, string& outFileName)
{
    ifstream input_file_stream;
    input_file_stream.open(inFileName, ios::binary);
    ofstream output_file_stream;
    output_file_stream.open(outFileName, ios::binary);

    string temp;
    string output;
    string input((istreambuf_iterator<char>(input_file_stream)),
                 (istreambuf_iterator<char>()));

    int dictionary_count;
    unsigned long long int index = 0;

    while(input[index] != '>')
    {
        temp += input[index];
        ++index;
    }
    index += 2;
    dictionary_count = stoi(temp);

    int need_index;

    getSubstrings(&input, ">=<<", need_index);

    map<string, unsigned char> _map;
    unsigned char temp_char;
    string temp_string = input.substr(index, need_index);
    string delimiter = ">=";
    string token;
    index += temp_string.length() - 1;

    makeMapForDecode(temp_string,temp,temp_char, _map);

    unsigned long long int bit_count;
    temp_string = "";
    while(input[index] != '>')
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
    getStringForEncode(encode, &code, &bit_count);

    getEncodedString(temp, output, encode, &_map);
    output_file_stream << output;

    input_file_stream.close();
    output_file_stream.close();
}

void compress_H(string& inFileName, string& outFileName)
{
    ifstream input_file_stream;
    input_file_stream.open(inFileName, ios::binary);
    ofstream output_file_stream;
    output_file_stream.open(outFileName, ios::binary);

    string output;
    string input((istreambuf_iterator<char>(input_file_stream)),
                 (istreambuf_iterator<char>()));

    //мап из сивола и его частоты
    map<unsigned char, unsigned long long int> counts;
    get_counts(&input, counts);

    //Создание вектора для сортировки значений мапа
    vector<pair<unsigned long long int, unsigned char>> counts_vec;
    for(auto it = counts.begin(); it != counts.end(); ++it)
        counts_vec.push_back(make_pair(it->second, it->first));

    //Сортируем вектор по убыванию
    sort(counts_vec.begin(), counts_vec.end());
    reverse(begin(counts_vec), end(counts_vec));

    //Создание кода Шенона Фано
    Huffman* huff = new Huffman();
    for(auto it = counts_vec.begin(); it != counts_vec.end(); ++it)
        huff->addChance(it->first);
    huff->build();

    string compress;

    map<unsigned char, string> _map;
    makeMapForEncode(_map, &counts_vec, &counts, &huff);
    writeMapToString(&_map, output);

    for(int i = 0; i < input.size(); ++i)
        compress += _map[input[i]];

    //запись кол-ва битов исходного файла
    output += to_string(compress.length()) + ">=";

    writeCodeInString(compress, output);

    output_file_stream << output;

    input_file_stream.close();
    output_file_stream.close();
    delete huff;
}

void compress_LZ77(string& inFileName, string& outFileName,
        int Buffer_Story_Length, int Buffer_Pre_Length)
{
    ifstream input_file_stream;
    input_file_stream.open(inFileName, ios::binary);

    ofstream output_file_stream;
    output_file_stream.open(outFileName, ios::binary);
    string input((istreambuf_iterator<char>(input_file_stream)),
                 (istreambuf_iterator<char>()));

    vector<LZ77::Node*> result_nodes;
    LZ77 _LZ77;
    _LZ77.encode(input, result_nodes, Buffer_Story_Length, Buffer_Pre_Length);

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
}

void decompress_LZ77(string& inFileName, string& outFileName)
{
    ifstream input_file_stream;
    input_file_stream.open(inFileName, ios::binary);

    ofstream output_file_stream;
    output_file_stream.open(outFileName, ios::binary);

    string output;

    LZ77 _LZ77;
    output = _LZ77.decode(&input_file_stream);
    output_file_stream << output;
    input_file_stream.close();
    output_file_stream.close();
}