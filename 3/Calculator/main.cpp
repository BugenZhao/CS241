//
// Created by Bugen Zhao on 2019/9/27.
//

#include "BZCalculator.h"
#include <iostream>

using namespace std;

int main() {
    BZCalculator calc;
    string exp;
    cout << "Calculator by BugenZhao." << endl;
    while (true) {
        cout << "calc> ";
        if (!getline(cin, exp) || exp == "exit" || exp == "EXIT") {
            cout << "Bye" << endl;
            return 0;
        }
        if (exp.empty()) continue;
        try {
            cout << calc.evaluate(exp) << endl;
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
}