#include <chrono>
#include "src/compressors/ShannonFano.cpp"
#include "src/compressors/LZ77.cpp"
#include <thread>
#include "src/compressors/LZW.cpp"
#include "src/compressors/Huffman.cpp"
#include "src/other/Compressor.cpp"

//Посчитать всю информацию для одного файла
void makeSingleExperement(string inputFileName, string compress1, string compress2,
                          string compress3, string compress4, string compress5, string compress6,
                          string compress7, string compress8, string compress9, string compress10,
                          string compress11,
                          string res1, string res2, string res3, string res4,
                          string res5, string res6, string res7, string res8, string res9,
                          string res10, string res11);

void printResults(const string& fileName, string& experiment_result);

int main()
{
    thread thread1(&makeSingleExperement, "DATA/1.txt", "1.shan", "1.lz775",
                      "1.lz7710", "1.lz7720", "1.huff", "1.lz775h", "1.lz7710h", "1.lz7720h",
                      "1.lz775sh_f", "1.lz7710sh_f", "1.lz7720sh_f",
                      "RESULTSHF/1.txt", "RESULTLZ775/1.txt","RESULTLZ7710/1.txt",
                      "RESULTLZ7720/1.txt", "RESULTH/1.txt", "RESULTLZ775H/1.txt", "RESULTLZ7710H/1.txt",
                      "RESULTLZ7720H/1.txt", "RESULTLZ775SHF/1.txt", "RESULTLZ7710SHF/1.txt",
                   "RESULTLZ7720SHF/1.txt");

    thread thread2(&makeSingleExperement, "DATA/2.docx", "2.shan", "2.lz775",
                   "2.lz7710", "2.lz7720", "2.huff", "2.lz775h", "2.lz7710h", "2.lz7720h",
                   "2.lz775sh_f", "2.lz7710sh_f", "2.lz7720sh_f",
                   "RESULTSHF/2.docx", "RESULTLZ775/2.docx","RESULTLZ7710/2.docx",
                   "RESULTLZ7720/2.docx", "RESULTH/2.docx", "RESULTLZ775H/2.docx", "RESULTLZ7710H/2.docx"
                   , "RESULTLZ7720H/2.docx", "RESULTLZ775SHF/2.docx", "RESULTLZ7710SHF/2.docx"
                    , "RESULTLZ7720SHF/2.docx");

    thread thread3(&makeSingleExperement, "DATA/3.pptx", "3.shan", "3.lz775",
                   "3.lz7710", "3.lz7720", "3.huff", "3.lz775h", "3.lz7710h", "3.lz7720h",
                   "3.lz775sh_f", "3.lz7710sh_f", "3.lz7720sh_f",
                   "RESULTSHF/3.pptx", "RESULTLZ775/3.pptx","RESULTLZ7710/3.pptx",
                   "RESULTLZ7720/3.pptx", "RESULTH/3.pptx", "RESULTLZ775H/3.pptx", "RESULTLZ7710H/3.pptx",
                   "RESULTLZ7720H/3.pptx", "RESULTLZ775SHF/3.pptx", "RESULTLZ7710SHF/3.pptx",
                   "RESULTLZ7720SHF/3.pptx");

    thread thread4(&makeSingleExperement, "DATA/4.png", "4.shan", "4.lz775",
                   "4.lz7710", "4.lz7720", "4.huff", "4.lz775h", "4.lz7710h", "4.lz7720h",
                   "4.lz775sh_f", "4.lz7710sh_f", "4.lz7720sh_f",
                   "RESULTSHF/4.png", "RESULTLZ775/4.png","RESULTLZ7710/4.png",
                   "RESULTLZ7720/4.png", "RESULTH/4.png", "RESULTLZ775H/4.png", "RESULTLZ7710H/4.png",
                   "RESULTLZ7720H/4.png", "RESULTLZ775SHF/4.png", "RESULTLZ7710SHF/4.png",
                   "RESULTLZ7720SHF/4.png");

    thread thread5(&makeSingleExperement, "DATA/5.pdf", "5.shan", "5.lz775",
                   "5.lz7710", "5.lz7720", "5.huff", "5.lz775h", "5.lz7710h", "5.lz7720h",
                   "5.lz775sh_f", "5.lz7710sh_f", "5.lz7720sh_f",
                   "RESULTSHF/5.pdf", "RESULTLZ775/5.pdf","RESULTLZ7710/5.pdf",
                   "RESULTLZ7720/5.pdf", "RESULTH/5.pdf", "RESULTLZ775H/5.pdf", "RESULTLZ7710H/5.pdf",
                   "RESULTLZ7720H/5.pdf", "RESULTLZ775SHF/5.pdf", "RESULTLZ7710SHF/5.pdf",
                   "RESULTLZ7720SHF/5.pdf");

    thread thread6(&makeSingleExperement, "DATA/6.xlsx", "6.shan", "6.lz775",
                   "6.lz7710", "6.lz7720", "6.huff", "6.lz775h", "6.lz7710h", "6.lz7720h",
                   "6.lz775sh_f", "6.lz7710sh_f", "6.lz7720sh_f",
                   "RESULTSHF/6.xlsx", "RESULTLZ775/6.xlsx","RESULTLZ7710/6.xlsx",
                   "RESULTLZ7720/6.xlsx", "RESULTH/6.xlsx", "RESULTLZ775H/6.xlsx", "RESULTLZ7710H/6.xlsx",
                   "RESULTLZ7720H/6.xlsx", "RESULTLZ775SHF/6.xlsx", "RESULTLZ7710SHF/6.xlsx",
                   "RESULTLZ7720SHF/6.xlsx");

    thread thread7(&makeSingleExperement, "DATA/7.bmp", "7.shan", "7.lz775",
                   "7.lz7710", "7.lz7720", "7.huff", "7.lz775h", "7.lz7710h", "7.lz7720h",
                   "7.lz775sh_f", "7.lz7710sh_f", "7.lz7720sh_f",
                   "RESULTSHF/7.bmp", "RESULTLZ775/7.bmp","RESULTLZ7710/7.bmp",
                   "RESULTLZ7720/7.bmp", "RESULTH/7.bmp", "RESULTLZ775H/7.bmp", "RESULTLZ7710H/7.bmp",
                   "RESULTLZ7720H/7.bmp", "RESULTLZ775SHF/7.bmp", "RESULTLZ7710SHF/7.bmp",
                   "RESULTLZ7720SHF/7.bmp");

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
        string compress3, string compress4, string compress5, string compress6, string compress7,
        string compress8, string compress9, string compress10,
        string compress11,string res1, string res2,
        string res3, string res4, string res5, string res6, string res7, string res8, string res9,
        string res10, string res11)
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

        experiment_result += "\nВремя сжатия для Шенона-Фано:\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_SH_F(inputFileName, compress1);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для Шенона-Фано:\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_SHF_or_H(compress1, res1);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для Хафмена:\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_H(inputFileName, compress5);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для Хафмена:\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_SHF_or_H(compress5, res5);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_5:\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77(inputFileName, compress2, 4096, 1024);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_5:\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77(compress2, res2);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_10:\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77(inputFileName, compress3, 8192, 2048);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_10:\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77(compress3, res3);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_20:\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77(inputFileName, compress4, 16384, 4096);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_20:\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77(compress4, res4);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';
        experiment_result += '\n';

        experiment_result += "\nВремя сжатия для LZ77_5 + Хафмен\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77_H(inputFileName, compress2, compress6, 4096, 1024);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_5 + Хафмен\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77_H_or_LZ77_SH_F(compress6, res2, res6);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_10 + Хафмен\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77_H(inputFileName, compress3, compress7, 8192, 2048);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_10 + Хафмен\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77_H_or_LZ77_SH_F(compress7, res3, res7);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_20 + Хафмен\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77_H(inputFileName, compress4, compress8, 16384, 4096);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_20 + Хафмен\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77_H_or_LZ77_SH_F(compress8, res4, res8);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_5 + Шенон-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77_SH_F(inputFileName, compress2, compress9, 4096, 1024);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_5 + Шенон-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77_H_or_LZ77_SH_F(compress9, res2, res9);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_10 + Шенон-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77_SH_F(inputFileName, compress3, compress10, 8192, 2048);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_10 + Шенон-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77_H_or_LZ77_SH_F(compress10, res3, res10);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя сжатия для LZ77_20 + Шенон-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->compress_LZ77_SH_F(inputFileName, compress4, compress11, 16384, 4096);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += "\nВремя распаковки для LZ77_20 + Шенон-Фано\n";
        duration1 = chrono::steady_clock::now();
        compressor->decompress_LZ77_H_or_LZ77_SH_F(compress11, res4, res11);
        duration2 = chrono::steady_clock::now();
        diff = duration2 - duration1;
        experiment_result += to_string(diff.count()) + " c" + '\n';

        experiment_result += '\n';

        compressor->findCompressionRatio(inputFileName, compress1, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress2, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress3, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress4, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress5, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress6, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress7, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress8, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress9, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress10, experiment_result);
        compressor->findCompressionRatio(inputFileName, compress11, experiment_result);

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