#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include "Support.cpp"
#include <cmath>
#include <algorithm>

class Compressor
{
public:

    Compressor();

    ~Compressor();

    //Метод сжатия по алгоритму Шеннона_Фано
    void compress_SH_F(string& inFileName, string& outFileName);

    //Метод сжатия по алгоритму Хафмена
    void compress_H(string& inFileName, string& outFileName);

    //Метод распаковки по алгоритму Шеннона_Фано или Хафмену
    void decompress_SHF_or_H(string& inFileName, string& outFileName);

    //Метод сжатия по алгоритму LZ77
    //Размер скользящего окна 5 Кб, размер словаря 4 Кб архивированный
    void compress_LZ77(string& inFileName, string& outFileName,
                        int Buffer_Story_Length, int Buffer_Pre_Length);

    void compress_LZ77_H(string& inFileName, string& outFileName,
                        int Buffer_Story_Length, int Buffer_Pre_Length);

    //Метод распаковки по алгоритму LZ77
    void decompress_LZ77(string& inFileName, string& outFileName);

    //Поиск коэффициентов сжатия
    void findCompressionRatio(const string& inputFile, string cFile, string& experiment_result);

    //Поиск энтропии файла
    void findEntropy(string* fileName, string& experiment_result);

    //Проверка существования файла
    bool checkFile(string* filePath);

private:

    LZ77* lz77;
    AlphabetConstructor* shannonFano;
    AlphabetConstructor* huffman;

    Support* support;

    //Обновление компрессора для Ш_Ф
    void refreshSH_F();

    //Обновление компрессора для Х
    void refreshH();

};

#endif