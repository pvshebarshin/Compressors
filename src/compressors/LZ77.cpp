#include "LZ77.h"

int *LZ77::pi(std::string str)
{
    int i;
    int n = str.length();
    int temp;
    int *bp = new int[n];
    bp[0] = 0;
    for (i = 1; i < n; ++i)
    {
        temp = bp[i - 1];
        while ((temp > 0) && (str[i] != str[temp]))
            temp = bp[temp - 1];
        if (str[i] == str[temp]){
            bp[i] = temp + 1;
        } else{
            bp[i] = 0;
        }
    }
    return bp;
}

void LZ77::getSubstrings(const std::string &source, const std::string &find)
{
    int pozition = 0;
    length = 0;
    offset = 0;
    int *br = pi(find);
    for (int i = 0; i < source.size(); i++)
    {
        while (pozition == find.length()
               || (pozition > 0 && find[pozition] != source[i]))
        {
            pozition = br[pozition - 1];
            if (find.length() - pozition > source.length() - i)
                break;
        }

        if (source[i] == find[pozition])
            ++pozition;

        if (pozition > length && i - pozition + 1 < position - border)
        {
            length = pozition;
            offset = position - border - i + pozition - 1;
        }
    }
    delete br;
}

std::string LZ77::find_reminder(std::string &str, int count)
{
    int k = 0;
    std::string res = "";
    for(int i = 0; i < count; ++i, ++k)
        if (k < str.size()){
            res += str[k];
        } else {
            k = 0;
            res += str[k];
        }
    return res;
}

void LZ77::take_value_from_file(std::string *input, int &help_index, std::string &temp)
{
    while((*input)[help_index] != ' ')
    {
        temp += (*input)[help_index];
        ++help_index;
    }
    ++help_index;
}

std::string LZ77::decode(std::ifstream *fin)
{
    int help_index = 0;
    std::string temp;
    std::string input((std::istreambuf_iterator<char>(*fin)),(std::istreambuf_iterator<char>()));

    take_value_from_file(&input, help_index, temp);

    int count;
    int index;
    int count_of_char;
    char ch;
    std::string res;
    std::string help_str;

    count = stoi(temp);
    temp = "";

    for (int i = 0; i < count; ++i)
    {
        take_value_from_file(&input, help_index, temp);
        index = stoi(temp);
        temp = "";

        take_value_from_file(&input, help_index, temp);
        count_of_char = stoi(temp);
        temp = "";

        ch = input[help_index];
        help_index += 2;

        help_str = "";
        for(int j = 0; j < count_of_char; ++j)
        {
            if(j == index)
            {
                help_str += find_reminder(help_str, count_of_char - index);
                break;
            }
            help_str += res[res.size() - index + j];
        }
        res += help_str + ch;
    }
    return res;}

void LZ77::encode(std::string &buffer, std::vector<Node *> &result_nodes,
                  int Buffer_Story_Length, int Buffer_Pre_Length)
{
    bufferBackstoryLength = Buffer_Story_Length;
    bufferPreviewLength = Buffer_Pre_Length;
    while (buffer.size() > position)
    {
        getSubstrings(buffer.substr(border,
                                    bufferPreviewLength + position - border),
                      buffer.substr(position, bufferPreviewLength));

        position += length + 1;

        if (position > bufferBackstoryLength)
            border = position - bufferBackstoryLength;

        result_nodes.emplace_back(new Node(offset, length, buffer[position - 1]));
    }
}

LZ77::Node::Node(int offset, int length, char next)
{
    this->offset = offset;
    this->length = length;
    this->ch = next;
}
