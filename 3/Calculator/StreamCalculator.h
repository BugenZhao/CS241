//
// Created by Bugen Zhao on 2019/9/27.
//

#ifndef CS241_STREAMCALCULATOR_H
#define CS241_STREAMCALCULATOR_H

#include "TokenStream.h"
#include "BaseAlgorithms.h"

class StreamCalculator {
    std::basic_istream<char> &in;
    TokenStream ts;
private:
    double expr();

    double factor();

    double term();

public:
    explicit StreamCalculator(std::basic_istream<char> &in);

    double calculate();
};


#endif //CS241_STREAMCALCULATOR_H
