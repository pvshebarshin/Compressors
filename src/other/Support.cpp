#include "Support.h"

void Support::get_counts(string *data, map<unsigned char, uint64_t> &count) noexcept
{
    for (char i : (*data))
        ++count[i];
}


void Support::writeMapToString(map<unsigned char, string> *_map, string &output)
{
    output += to_string((*_map).size()) + ">=";
    for (auto& it : (*_map))
    {
        output += it.first;
        output += ">=" + it.second + ">=";
    }
    output += "<<";
}

void Support::writeCodeInString(string& compress, string& output)
{
    if(compress.length() % 8 != 0)
        while (compress.length() % 8 != 0)
            compress += '0';

    stringstream ss(compress);
    bitset<8> bits;
    while (ss.good())
    {
        ss >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }
}

void Support::getSubstrings(string* source, string substring, int& res)
{
    int *p = pi(substring);
    int count = 0;

    for (int i = 0; i < (*source).length(); ++i)
    {
        while (count > 0 && substring[count] != (*source)[i])
            count = p[count - 1];

        if (substring[count] == (*source)[i])
            ++count;

        if (count == substring.length())
        {
            res = i - (int) substring.length() + 1;
            delete[] p;
            return;
        }
    }
}

int* Support::pi(string str) noexcept
{
    int i;
    int *pi = new int[str.size()];
    for(i = 0; i < str.size(); ++i)
        pi[i] = 0;

    int k = 0;

    for (i = 1; i < str.size(); ++i)
    {
        while (k > 0 && str[i] != str[k])
            k = pi[k - 1];
        if (str[i] == str[k])
            ++k;
        pi[i] = k;
    }

    return pi;
}

void Support::makeMapForDecode(string &temp, string &temp_string, unsigned char &temp_char,
                               map<string, unsigned char> &_map)
{
    unsigned int pos = 0;
    unsigned int help = 0;
    string delimiter = ">=";
    string token;

    vector<unsigned char> uc_vec;
    vector<string> s_vec;
    while ((pos = temp.find(delimiter)) != string::npos)
    {
        if(help % 2 == 0)
        {
            token = temp.substr(0, pos);
            temp_char = token[0];
            uc_vec.push_back(temp_char);
        } else {
            token = temp.substr(0, pos);
            temp_string = token;
            s_vec.push_back(temp_string);
        }
        ++help;
        temp.erase(0, pos + delimiter.length());
    }
    for (int i = 0; i < s_vec.size(); ++i)
        _map.insert(make_pair(s_vec[i], uc_vec[i]));
}

void Support::getStringForEncode(string& encode, string* code, const uint64_t *bit_count)
{
    for(char i : *code)
        encode += bitset<8>(i).to_string();
    encode = encode.substr(0, *bit_count);
}

void Support::getEncodedString(string &temp, string &output,
                               string &encode, map<string, unsigned char> *_map)
{
    temp = "";
    for(char i : encode)
    {
        temp += i;
        if ((*_map).find(temp) != (*_map).end())
        {
            output += (*_map)[temp];
            temp = "";
        }
    }
}

void Support::makeMapForEncode(map<unsigned char, string> &_map,
                               vector<pair<uint64_t , unsigned char>> *counts_vec,
                               map<unsigned char, uint64_t> *counts, AlphabetConstructor* *algo) noexcept
{
    for(auto& it : *counts)
        for(int i = 0; i < (*counts_vec).size(); ++i)
            if((*counts_vec)[i].first == it.second)
                _map.insert(make_pair((*counts_vec)[i].second, (*algo)->get(i)));
}