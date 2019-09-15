#include "solve.h"
#include <iostream>

using namespace std;


int main() {
    double a, b, c;
    cin >> a >> b >> c;
    if (cin.fail() || fabs(a) < 1e-6) {
        cerr << "Illegal inputs!" << endl;
        return -1;
    }
    try {
        auto solution = solve(a, b, c);
        cout << "x1 = " << solution[0] << "\nx2 = " << solution[1] << endl;
    } catch (const runtime_error &) {
        cerr << "b^2 − 4ac is less than zero!" << endl;
        return -2;
    }
    return 0;
}
