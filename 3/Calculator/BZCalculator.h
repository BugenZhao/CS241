//
// Created by Bugen Zhao on 2019/9/27.
//

#ifndef CS241_BZCALCULATOR_H
#define CS241_BZCALCULATOR_H

#include "StreamCalculator.h"
#include <sstream>
#include <algorithm>
#include <map>

using std::string, std::istringstream, std::map, std::find;

class BZCalculator {
    istringstream in;
    StreamCalculator sc;
    map<string, double> table;

private:
    string replaceVariables(const string &exp);

public:
    BZCalculator();

    double evaluate(const string &exp);

    double calculate(const string &exp);
};

bool isValidVariable(const string &str);

string &replace_all(string &str, const string &old_value, const string &new_value);

#endif //CS241_BZCALCULATOR_H
