#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <vector>

class Huffman
{

private:

    class Node
    {
    public:
        Node *left;
        Node *right;
        int value;
        int index;
        string code;
    };

    vector<Node*> row;

public:

    // зупскает алгоритм (после того как были добавлены все элементы)
    void build();

    // добавляет элемент в список (дерево, все зависит от реализации)
    void addChance (int chance);

    // выдает битовый код i символа
    string get (int i);

    Node* huffmanTree(int length);

    void traverse(Node* root, string &s);

    ~Huffman();

};

#endif