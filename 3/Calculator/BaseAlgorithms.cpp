//
// Created by Bugen Zhao on 2019/9/27.
//

#include "BaseAlgorithms.h"

string strip(const string &str, char ch) {
    string::size_type i = 0;
    while (str[i] == ch)
        i++;
    string::size_type j = str.size() - 1;
    while (str[j] == ch)
        j--;
    return str.substr(i, j + 1 - i);
}