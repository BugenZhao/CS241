//
// Created by Bugen Zhao on 2019/9/27.
//

#include "BZCalculator.h"
#include <iostream>

using namespace std;

int main() {
    string exp;
    while (getline(cin, exp))
        cout << BZCalculator::calculate(exp) << endl;
}