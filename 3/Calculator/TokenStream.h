//
// Created by Bugen Zhao on 2019/9/27.
//

#ifndef CS241_TOKENSTREAM_H
#define CS241_TOKENSTREAM_H

#include "Token.h"
#include <istream>

using std::istream;

class TokenStream {
    istream &in;
    Token buffer;
    bool full = false;
public:
    explicit TokenStream(istream &in);

    Token get();

    void putback(Token token);
};

#include <istream>
#include "Token.h"

#endif //CS241_TOKENSTREAM_H
