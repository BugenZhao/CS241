//
// Created by Bugen Zhao on 2019/9/27.
//

#include "BZCalculator.h"

double BZCalculator::calculate(const string &exp) {
    in.str(exp + ';');
    return sc.calculate();
}

BZCalculator::BZCalculator() : in(istringstream()), sc(in), table() {
    table["ans"] = 0.0;
}

double BZCalculator::evaluate(const string &exp) {
    int equalPos = exp.find('=');
    if (equalPos != string::npos) {
        string variable = strip(exp.substr(0, equalPos));
        string pExp = strip(exp.substr(equalPos + 1, exp.size()));
        if (isValidVariable(variable)) {
            double val = evaluate(pExp);
            table[variable] = val;
            return val;
        } else {
            throw std::runtime_error("'" + variable + "' is not a valid name");
        }
    } else {
        string nExp = replaceVariables(exp);
        return table["ans"] = calculate(nExp);
    }
}

string BZCalculator::replaceVariables(const string &exp) {
    string ret((exp));
    for (auto &it : table) {
        replace_all(ret, it.first, std::to_string(it.second));
    }
    return ret;
}

bool isValidVariable(const string &str) {
    bool hasAlpha = false;
    for (char c:str) {
        if (!isalnum(c)) return false;
        if (isalpha(c)) hasAlpha = true;
    }
    return hasAlpha && str != "ans" && str != "exit";
}

string &replace_all(string &str, const string &old_value, const string &new_value) {
    string::size_type pos = 0;
    while ((pos = str.find(old_value)) != string::npos) {
        str = str.replace(str.find(old_value), old_value.length(), new_value);
    }
    return str;
}