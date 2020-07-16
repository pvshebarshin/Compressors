#ifndef SHANNONFANO_H
#define SHANNONFANO_H

#include <vector>

class ShannonFano
{

public:
    ShannonFano(){}

    ~ShannonFano();

    //Реализация алгоритма
    void fillTree(int *left, int *right, int sum);

    // запускает алгоритм (после того как были добавлены все элементы)
    void build();

    // добавляет элемент в список
    void addChance (int chance);

    // выдает битовый код i символа
    std::string get (int i);

private:
    std::vector<int> chances;
    int* values = nullptr;
    std::string* codes = nullptr;
    int sum = 0;
};

#endif