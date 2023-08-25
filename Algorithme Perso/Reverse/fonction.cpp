#include"fonction.h"

void xor_string(std::string* str1, const std::string str2, const std::string str3)
{
    std::string val1 = str2;
    std::string val2 = str3;

    for (int i = 0; i < str2.length(); ++i) {
        str1[0] += char(val1[i] ^ val2[i]);
    }
}