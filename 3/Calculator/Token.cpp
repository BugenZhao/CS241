//
// Created by Bugen Zhao on 2019/9/27.
//

#include "Token.h"

Token::Token() : Token('\0', 0.0) {}

Token::Token(char kind, double value) : _kind(kind), _value(value) {}

char Token::kind() const {
    return _kind;
}

double Token::value() const {
    if (_kind != NUMBER) throw std::runtime_error(std::string("Bad token: '") + _kind + "'");
    else return _value;
}
