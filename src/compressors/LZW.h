#ifndef LZW_H
#define LZW_H

#include <map>
#include <fstream>

class LZW
{
public:
    void decode(const string &compressed_filename);

    string encode(const string &original_filename);

private:
    void read_all_compressed(ifstream &compressed, string &str);

    void decompress_all(string &compressed_str, map<int, string> &dict_i2s,
            map<string, int> &dict_s2i, int dict_size,string &res);

    string read_complete_file(ifstream &input);

    void write_to_file(ofstream &output, string &str_to_write);

    void compress_all(map<string, int> dict, int dict_size, string &inp_str, string &res);
};

#endif