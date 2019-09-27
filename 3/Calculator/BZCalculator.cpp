//
// Created by Bugen Zhao on 2019/9/27.
//

#include "BZCalculator.h"

double BZCalculator::calculate(const string &exp) {
    auto in = istringstream(exp + ";");
    StreamCalculator sc(in);
    return sc.calculate();
}
