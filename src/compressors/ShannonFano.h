#ifndef SHANNONFANO_H
#define SHANNONFANO_H

#include <vector>
#include "AlphabetConstructor.h"

class ShannonFano : public AlphabetConstructor
{

public:
    ShannonFano() = default;

    ~ShannonFano() override;

    //Реализация алгоритма
    void fillTree(int *left, int *right, int sum);

    // запускает алгоритм (после того как были добавлены все элементы)
    void build() override;

    // добавляет элемент в список
    void addChance (int chance) override;

    // выдает битовый код i символа
    std::string get (int i) override;

private:
    std::vector<int> chances;
    int* values = nullptr;
    std::string* codes = nullptr;
    int sum = 0;
};

#endif