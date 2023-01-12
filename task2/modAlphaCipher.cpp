#include "modAlphaCipher.h"
string modAlphaCipher::decoder(const std::string& cipher_st)
{
    string s = getValidText(cipher_st);
    string n_s = s;
    int len, number_of_lines, position, a;
    len = s.size();
    number_of_lines = (len - 1) / key + 1;
    a = 0;
    for(int colum_number = key; colum_number > 0; colum_number--) {
        for(int line_number = 0; line_number < number_of_lines; line_number++) {
            position = key * line_number + colum_number;
            if(position - 1 < len) {
                n_s[position - 1] = s[a];
                a++;
            }
        }
    }
    return n_s;
}
string modAlphaCipher::coder(const string& open_st)
{
    string s = getValidText(open_st);
    string n_s = s;
    int len, number_of_lines, position, a;
    len = s.size();
    number_of_lines = (len - 1) / key + 1;
    a = 0;
    for(int colum_number = key; colum_number > 0; colum_number--) {
        for(int line_number = 0; line_number < number_of_lines; line_number++) {
            position = colum_number + key * line_number;
            if(position - 1 < len) {
                n_s[a] = open_st[position - 1];
                a++;
            }
        }
    }
    return n_s;
}
inline std::string modAlphaCipher::getValidText(const std::string & s)
{
    string tmp;
    for(auto c:s) {
        if(isalpha (c)) {
            if(islower (c))
                tmp.push_back(toupper(c));
            else
                tmp.push_back(c);
        }
    }
    if(tmp.empty())
        throw cipher_error("Empty open text");
    return tmp;
}
