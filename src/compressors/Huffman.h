#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <vector>
#include "AlphabetConstructor.h"

class Huffman : public AlphabetConstructor
{

private:

    class Node
    {
    public:
        Node *left;
        Node *right;
        int value;
        int index;
        std::string code;
    };

    std::vector<Node*> row;

public:

    // зупскает алгоритм (после того как были добавлены все элементы)
    void build() override;

    // добавляет элемент в список (дерево, все зависит от реализации)
    void addChance (int chance) override;

    // выдает битовый код i символа
    std::string get (int i) override;

    Node* huffmanTree(int length);

    void traverse(Node* root, std::string &s);

    ~Huffman() override;

    Huffman() = default;

};

#endif