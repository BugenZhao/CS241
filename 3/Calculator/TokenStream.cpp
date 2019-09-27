//
// Created by Bugen Zhao on 2019/9/27.
//

#include "StreamCalculator.h"
#include "TokenStream.h"

TokenStream::TokenStream(istream &in) : in(in) {}

Token TokenStream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    in >> ch;
    switch (ch) {
        case '(':
        case ')':
        case ';':
        case 'q':
        case '+':
        case '-':
        case '*':
        case '/':
            return Token{ch, 0.0};
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9': {
            in.putback(ch);
            double val;
            in >> val;
            return Token{Token::NUMBER, val};
        }
        default:
            throw std::runtime_error(std::string("Bad token: '") + ch + '\'');
    }
}

void TokenStream::putback(Token token) {
    if (full) throw std::runtime_error("Buffer is full");
    buffer = token, full = true;
}