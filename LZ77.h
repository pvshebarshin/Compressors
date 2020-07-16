#ifndef LZ77_H
#define LZ77_H

#include <vector>
using namespace std;

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
    static int *pi(string str);

    //Поиск подстроки в строке по алгоритму Кнута-Мориса-Пратта
    void getSubstrings(const string &source, const string &find);

    //Вспомогательный метод для поиска остатка строки, когда
    //offset < length
    string find_reminder(string& str, int count);


    //Считывает значения из файла
    void take_value_from_file(string* input, int& help_index, string& temp);

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

    string decode(ifstream* fin);

    void encode(string& buffer, vector<Node*>& result_nodes,
                int Buffer_Story_Length = 4096, int Buffer_Pre_Length = 1024);

};

#endif