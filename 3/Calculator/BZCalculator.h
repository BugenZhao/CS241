//
// Created by Bugen Zhao on 2019/9/27.
//

#ifndef CS241_BZCALCULATOR_H
#define CS241_BZCALCULATOR_H

#include "StreamCalculator.h"
#include <sstream>

using std::string, std::istringstream;

class BZCalculator {
public:
    static double calculate(const string &exp);
};


#endif //CS241_BZCALCULATOR_H
