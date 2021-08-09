#ifndef LZ77_H
#define LZ77_H

#include <vector>
#include <fstream>
#include <string>

class LZ77
{
private:
    int bufferPreviewLength = 1024;
    int bufferBackstoryLength = 4096;
    int position = 0;
    int border = 0;
    int offset = 0;
    int length = 0;

    //Создание вспомогательного массива для
    //алгоритма Кнута-Мориса-Пратта
    static int* pi(std::string str);

    //Поиск подстроки в строке по алгоритму Кнута-Мориса-Пратта
    void getSubstrings(const std::string &source, const std::string &find);

    //Вспомогательный метод для поиска остатка строки, когда
    //offset < length
    std::string find_reminder(std::string& str, int count);


    //Считывает значения из файла
    void take_value_from_file(std::string* input, int& help_index, std::string& temp);

public:

    //Класс для более удобного представления Тройки
    class Node
    {
    public:
        int offset;
        int length;
        char ch;

        Node(int offset, int length, char next);

    };

    std::string decode(std::ifstream* fin);

    void encode(std::string& buffer, std::vector<Node*>& result_nodes,
                int Buffer_Story_Length = 4096, int Buffer_Pre_Length = 1024);

};

#endif