#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

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

    void build()
    {
        // зупскает алгоритм (после того как были добавлены все элементы)
        string s;
        traverse(huffmanTree(row.size()), s);
    }
    void addChance (int chance)
    {
        // добавляет элемент в список (дерево, все зависит от реализации)
        Node* node = new Node();
        node->value = chance;
        node->index = row.size();
        row.push_back(node);
    }
    string get (int i)
    {
        // выдает битовый код i символа
        return row[i]->code;
    }

    Node* huffmanTree(int length)
    {
        Node *item = new Node();

        item->value = row[length - 1]->value + row[length - 2]->value;
        item->left = row[length - 1];
        item->right = row[length - 2];

        if (length < 3){
            return item;
        }else{
            for (int i = 0; i < length; ++i)
                if (item->value > row[i]->value)
                {
                    for (int j = length - 1; j > i; --j)
                        row[j] = row[j - 1];
                    row[i] = item;
                    break;
                }
        }
        return huffmanTree(length - 1);
    }

    void traverse(Node* root, string &s)
    {
        if (root->left && root->right){

            s.push_back('0');
            traverse(root->left, s);
            s.pop_back();

            s.push_back('1');
            traverse(root->right, s);
            s.pop_back();

            delete root;
        }else{
            root->code = s;
            row[root->index] = root;
        }
    }

    ~Huffman()
    {
        for (int i = 0; i < row.size(); i++)
            delete row[i];
    }

};