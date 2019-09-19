//
// Created by Bugen Zhao on 2019/9/20.
//

#include "NewtonInterpolation.h"

using namespace std;

int main() {
    NewtonInterpolation newtonInterpolation;
    newtonInterpolation.DividedDifferenceTable();
    cout << endl;

    double x;
    while (true) {
        cin >> x;
        if (cin.fail()) break;
        cout << newtonInterpolation.ApproximateValue(x) << endl;
    }

}