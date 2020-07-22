#include <chrono>
#include "src/compressors/ShannonFano.cpp"
#include "src/compressors/LZ77.cpp"
#include <thread>
#include "src/compressors/LZW.cpp"
#include "src/compressors/Huffman.cpp"
#include "src/other/Compressor.cpp"

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
    Compressor* compressor = new Compressor();
    if(compressor->checkFile(&inputFileName))
    {
        //Строка для вывода результатов опыта
        string experiment_result = "Эксперемент над файлом " + inputFileName + '\n';

        compressor->findEntropy(&inputFileName, experiment_result);

        chrono::steady_clock::time_point duration1;
        chrono::steady_clock::time_point duration2;
        chrono::duration<double> diff{};

        experiment_result += "\nВремя сжатия для Шенона-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_SH_F(inputFileName, compress1);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя распаковки для Шенона-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_SHF_or_H(compress1, res1);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя сжатия для Хафмена\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_H(inputFileName, compress5);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

        experiment_result += "\nВремя распаковки для Хафмена\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_SHF_or_H(compress5, res5);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + '\n';

//        experiment_result += "\nВремя сжатия для LZ77_5\n";
//        duration1 = chrono::steady_clock::now();
//        compressor->compress_LZ77(inputFileName, compress2, 4096, 1024);
//        duration2 = chrono::steady_clock::now();
//        diff = duration2 - duration1;
//        experiment_result += to_string(diff.count()) + '\n';
//
//        experiment_result += "\nВремя распаковки для LZ77_5\n";
//        duration1 = chrono::steady_clock::now();
//        compressor->decompress_LZ77(compress2, res2);
//        duration2 = chrono::steady_clock::now();
//        diff = duration2 - duration1;
//        experiment_result += to_string(diff.count()) + '\n';
//
//        experiment_result += "\nВремя сжатия для LZ77_10\n";
//        duration1 = chrono::steady_clock::now();
//        compressor->compress_LZ77(inputFileName, compress3, 8192, 2048);
//        duration2 = chrono::steady_clock::now();
//        diff = duration2 - duration1;
//        experiment_result += to_string(diff.count()) + '\n';
//
//        experiment_result += "\nВремя распаковки для LZ77_10\n";
//        duration1 = chrono::steady_clock::now();
//        compressor->decompress_LZ77(compress3, res3);
//        duration2 = chrono::steady_clock::now();
//        diff = duration2 - duration1;
//        experiment_result += to_string(diff.count()) + '\n';
//
//        experiment_result += "\nВремя сжатия для LZ77_20\n";
//        duration1 = chrono::steady_clock::now();
//        compressor->compress_LZ77(inputFileName, compress4, 16384, 4096);
//        duration2 = chrono::steady_clock::now();
//        diff = duration2 - duration1;
//        experiment_result += to_string(diff.count()) + '\n';
//
//        experiment_result += "\nВремя распаковки для LZ77_20\n";
//        duration1 = chrono::steady_clock::now();
//        compressor->decompress_LZ77(compress4, res4);
//        duration2 = chrono::steady_clock::now();
//        diff = duration2 - duration1;
//        experiment_result += to_string(diff.count()) + '\n';
//        experiment_result += '\n';

        compressor->findCompressionRatio(inputFileName, compress1, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress2, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress3, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress4, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress5, experiment_result);

        string number;
        for(char item : inputFileName)
            if(item >= '0' && item <= '9')
                number += item;

        printResults("output" + number + ".txt", experiment_result);
    }else{
        cout << "file " + inputFileName + " not founded\n";
    }
    delete compressor;
}

void printResults(const string& fileName, string& experiment_result)
{
    ofstream output_file_stream;
    output_file_stream.open(fileName, ios::binary);
    output_file_stream << experiment_result;
    output_file_stream.close();
}