#ifndef ALPHABETCONSTRUCTOR_H
#define ALPHABETCONSTRUCTOR_H

#include <string>

class AlphabetConstructor
{
public:
    // запускает алгоритм (после того как были добавлены все элементы)
    virtual void build() = 0;

    // добавляет элемент в список
    virtual void addChance(int chance) = 0;

    // выдает битовый код i символа
    virtual std::string get(int i) = 0;

    virtual ~AlphabetConstructor() = default;
};

#endif
