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
    thread thread1(&makeSingleExperement, "../data/DATA/1.txt", "../data/1.shan", "../data/1.lz775",
                      "../data/1.lz7710", "../data/1.lz7720", "../data/1.huff", "../data/1.lz775h",
                      "../data/1.lz7710h", "../data/1.lz7720h", "../data/1.lz775sh_f",
                      "../data/1.lz7710sh_f", "../data/1.lz7720sh_f",
                      "../data/RESULTSHF/1.txt", "../data/RESULTLZ775/1.txt","../data/RESULTLZ7710/1.txt",
                      "../data/RESULTLZ7720/1.txt", "../data/RESULTH/1.txt", "../data/RESULTLZ775H/1.txt",
                      "../data/RESULTLZ7710H/1.txt", "../data/RESULTLZ7720H/1.txt",
                      "../data/RESULTLZ775SHF/1.txt", "../data/RESULTLZ7710SHF/1.txt",
                      "../data/RESULTLZ7720SHF/1.txt");

    thread thread2(&makeSingleExperement, "../data/DATA/2.docx", "../data/2.shan", "../data/2.lz775",
                   "../data/2.lz7710", "../data/2.lz7720", "../data/2.huff", "../data/2.lz775h",
                   "../data/2.lz7710h", "../data/2.lz7720h", "../data/2.lz775sh_f", "../data/2.lz7710sh_f",
                   "../data/2.lz7720sh_f", "../data/RESULTSHF/2.docx", "../data/RESULTLZ775/2.docx",
                   "../data/RESULTLZ7710/2.docx", "../data/RESULTLZ7720/2.docx", "../data/RESULTH/2.docx",
                   "../data/RESULTLZ775H/2.docx", "../data/RESULTLZ7710H/2.docx",
                   "../data/RESULTLZ7720H/2.docx", "../data/RESULTLZ775SHF/2.docx",
                   "../data/RESULTLZ7710SHF/2.docx", "../data/RESULTLZ7720SHF/2.docx");

    thread thread3(&makeSingleExperement, "../data/DATA/3.pptx", "../data/3.shan", "../data/3.lz775",
                   "../data/3.lz7710", "../data/3.lz7720", "../data/3.huff", "../data/3.lz775h",
                   "../data/3.lz7710h", "../data/3.lz7720h", "../data/3.lz775sh_f", "../data/3.lz7710sh_f",
                   "../data/3.lz7720sh_f", "../data/RESULTSHF/3.pptx", "../data/RESULTLZ775/3.pptx",
                   "../data/RESULTLZ7710/3.pptx", "../data/RESULTLZ7720/3.pptx", "../data/RESULTH/3.pptx",
                   "../data/RESULTLZ775H/3.pptx", "../data/RESULTLZ7710H/3.pptx",
                   "../data/RESULTLZ7720H/3.pptx", "../data/RESULTLZ775SHF/3.pptx",
                   "../data/RESULTLZ7710SHF/3.pptx", "../data/RESULTLZ7720SHF/3.pptx");

    thread thread4(&makeSingleExperement, "../data/DATA/4.png", "../data/4.shan", "../data/4.lz775",
                   "../data/4.lz7710", "../data/4.lz7720", "../data/4.huff", "../data/4.lz775h",
                   "../data/4.lz7710h", "../data/4.lz7720h", "../data/4.lz775sh_f", "../data/4.lz7710sh_f",
                   "../data/4.lz7720sh_f", "../data/RESULTSHF/4.png", "../data/RESULTLZ775/4.png",
                   "../data/RESULTLZ7710/4.png", "../data/RESULTLZ7720/4.png", "../data/RESULTH/4.png",
                   "../data/RESULTLZ775H/4.png", "../data/RESULTLZ7710H/4.png",
                   "../data/RESULTLZ7720H/4.png", "../data/RESULTLZ775SHF/4.png",
                   "../data/RESULTLZ7710SHF/4.png", "../data/RESULTLZ7720SHF/4.png");

    thread thread5(&makeSingleExperement, "../data/DATA/5.pdf", "../data/5.shan", "../data/5.lz775",
                   "../data/5.lz7710", "../data/5.lz7720", "../data/5.huff", "../data/5.lz775h",
                   "../data/5.lz7710h", "../data/5.lz7720h", "../data/5.lz775sh_f", "../data/5.lz7710sh_f",
                   "../data/5.lz7720sh_f", "../data/RESULTSHF/5.pdf", "../data/RESULTLZ775/5.pdf",
                   "../data/RESULTLZ7710/5.pdf", "../data/RESULTLZ7720/5.pdf", "../data/RESULTH/5.pdf",
                   "../data/RESULTLZ775H/5.pdf", "../data/RESULTLZ7710H/5.pdf",
                   "../data/RESULTLZ7720H/5.pdf", "../data/RESULTLZ775SHF/5.pdf",
                   "../data/RESULTLZ7710SHF/5.pdf", "../data/RESULTLZ7720SHF/5.pdf");

    thread thread6(&makeSingleExperement, "../data/DATA/6.xlsx", "../data/6.shan", "../data/6.lz775",
                   "../data/6.lz7710", "../data/6.lz7720", "../data/6.huff", "../data/6.lz775h",
                   "../data/6.lz7710h", "../data/6.lz7720h", "../data/6.lz775sh_f", "../data/6.lz7710sh_f",
                   "../data/6.lz7720sh_f", "../data/RESULTSHF/6.xlsx", "../data/RESULTLZ775/6.xlsx",
                   "../data/RESULTLZ7710/6.xlsx", "../data/RESULTLZ7720/6.xlsx", "../data/RESULTH/6.xlsx",
                   "../data/RESULTLZ775H/6.xlsx", "../data/RESULTLZ7710H/6.xlsx",
                   "../data/RESULTLZ7720H/6.xlsx", "../data/RESULTLZ775SHF/6.xlsx",
                   "../data/RESULTLZ7710SHF/6.xlsx", "../data/RESULTLZ7720SHF/6.xlsx");

    thread thread7(&makeSingleExperement, "../data/DATA/7.bmp", "../data/7.shan", "../data/7.lz775",
                   "../data/7.lz7710", "../data/7.lz7720", "../data/7.huff", "../data/7.lz775h",
                   "../data/7.lz7710h", "../data/7.lz7720h", "../data/7.lz775sh_f", "../data/7.lz7710sh_f",
                   "../data/7.lz7720sh_f", "../data/RESULTSHF/7.bmp", "../data/RESULTLZ775/7.bmp",
                   "../data/RESULTLZ7710/7.bmp", "../data/RESULTLZ7720/7.bmp", "../data/RESULTH/7.bmp",
                   "../data/RESULTLZ775H/7.bmp", "../data/RESULTLZ7710H/7.bmp",
                   "../data/RESULTLZ7720H/7.bmp", "../data/RESULTLZ775SHF/7.bmp",
                   "../data/RESULTLZ7710SHF/7.bmp", "../data/RESULTLZ7720SHF/7.bmp");

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

        printResults("../data/output" + number + ".txt", experiment_result);
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