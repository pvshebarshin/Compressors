#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include "Support.cpp"
#include <cmath>
#include <algorithm>

class Compressor
{
public:

    Compressor() noexcept;

    ~Compressor() noexcept;

    //Метод сжатия по алгоритму Шеннона_Фано
    void compress_SH_F(const string& inFileName, const string& outFileName);

    //Метод сжатия по алгоритму Хафмена
    void compress_H(const string& inFileName, const string& outFileName);

    //Метод распаковки по алгоритму Шеннона_Фано или Хафмену
    void decompress_SHF_or_H(const string& inFileName, const string& outFileName);

    //Метод сжатия по алгоритму LZ77
    //Размер скользящего окна 5 Кб, размер словаря 4 Кб архивированный
    void compress_LZ77(const string& inFileName, const string& outFileName,
                        int Buffer_Story_Length, int Buffer_Pre_Length);

    //Метод сжатия по алгоритмам LZ77 и Хафмену
    void compress_LZ77_H(const string& inFileName, const string& outFileName1, const string& outFileName2,
                        int Buffer_Story_Length, int Buffer_Pre_Length);

    //Метод сжатия по алгоритмам LZ77 и Шенону-Фано
    void compress_LZ77_SH_F(const string& inFileName, const string& outFileName1, const string& outFileName2,
                            int Buffer_Story_Length, int Buffer_Pre_Length);

    //Метод распаковки по алгоритму LZ77
    void decompress_LZ77(const string& inFileName, const string& outFileName);

    //Метод распаковки LZ77 и Хафмена или LZ77 и Шенона-Фано
    void decompress_LZ77_H_or_LZ77_SH_F(const string& inFileName, const string& outFileName1, const string& outFileName2);

    //Поиск коэффициентов сжатия
    void findCompressionRatio(const string& inputFile, string cFile, string& experiment_result) const noexcept;

    //Поиск энтропии файла
    void findEntropy(const string* fileName, string& experiment_result) const noexcept;

    //Проверка существования файла
    bool checkFile(const string* filePath) const noexcept;

private:

    LZ77* lz77 = nullptr;
    AlphabetConstructor* shannonFano = nullptr;
    AlphabetConstructor* huffman = nullptr;

    Support* support = nullptr;

    //Обновление компрессора для Ш_Ф
    void refreshSH_F() noexcept;

    //Обновление компрессора для Х
    void refreshH() noexcept;

    //Обновление компрессора для LZ77
    void refreshLZ77() noexcept;

    //Обновление компрессора для LZW
    void refreshLZW() noexcept;

};

#endif