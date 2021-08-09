#include "Huffman.h"

void Huffman::build()
{
    std::string s;
    traverse(huffmanTree(row.size()), s);
}

void Huffman::addChance(int chance)
{
    Node* node = new Node();
    node->value = chance;
    node->index = row.size();
    row.push_back(node);
}

std::string Huffman::get(int i)
{
    return row[i]->code;
}

Huffman::~Huffman()
{
    for (int i = 0; i < row.size(); ++i)
        delete row[i];
}

void Huffman::traverse(Huffman::Node *root, std::string &s)
{
    if (root->left && root->right){

        s.push_back('0');
        traverse(root->left, s);
        s.pop_back();

        s.push_back('1');
        traverse(root->right, s);
        s.pop_back();

        delete root;
    } else {
        root->code = s;
        row[root->index] = root;
    }
}

Huffman::Node *Huffman::huffmanTree(int length) {
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

