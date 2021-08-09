#ifndef SUPPORT_H
#define SUPPORT_H

#include <sstream>
#include <bitset>
#include <map>
#include "../compressors/AlphabetConstructor.h"
#include <vector>


using namespace std;

class Support
{
public:

    //Нахождение частот всех символов
    void get_counts(string* data, map<unsigned char, uint64_t>& count) noexcept;

    //Создание вспомогательного map для кодирования
    void makeMapForEncode(map<unsigned char, string>& _map,
                          vector<pair<uint64_t , unsigned char>>* counts_vec,
                          map<unsigned char, uint64_t>* counts,
                          AlphabetConstructor* *algo) noexcept;

    //Запись map в строку
    void writeMapToString(map<unsigned char, string>* _map, string& output);

    //Запись битов кода в строку
    void writeCodeInString(string& compress, string& output);

    //Поиск нулевого индекса первого вхождения строки в строку
    //по алгоритму Кнута-Мориса_Пратта
    void getSubstrings(string* source, string substring, int& res);

    //Создание вспомогательного map для декодирования
    void makeMapForDecode(string& temp, string& temp_string, unsigned char& temp_char,
                          map<string, unsigned char>& _map);

    //Получить строчку для декодирования из 0 и 1
    void getStringForEncode(string& encode, string* code, const uint64_t* bit_count);

    //Декодирование строки из 0 и 1
    void getEncodedString(string& temp, string& output,
                          string& encode,map<string, unsigned char>* _map);

private:

    //Создание вспомогательного массива для
    //алгоритма Кнута-Мориса-Пратта
    int* pi(string str) noexcept;
};

#endif