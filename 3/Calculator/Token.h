//
// Created by Bugen Zhao on 2019/9/27.
//

#ifndef CS241_TOKEN_H
#define CS241_TOKEN_H

#include <stdexcept>
#include <string>

class Token {
    char _kind{};
    double _value{};
public:
    constexpr static char NUMBER = '8';

    Token();

    Token(char kind, double value);

    char kind() const;

    double value() const;
};

#endif //CS241_TOKEN_H
