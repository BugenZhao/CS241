//
// Created by Bugen Zhao on 2019/9/27.
//

#ifndef CS241_STREAMCALCULATOR_H
#define CS241_STREAMCALCULATOR_H

#include "TokenStream.h"

using std::istream;

class StreamCalculator {
    istream &in;
    TokenStream ts;
private:
    double expression();

    double primary();

    double term();

public:
    explicit StreamCalculator(istream &in);

    double calculate();
};


#endif //CS241_STREAMCALCULATOR_H
