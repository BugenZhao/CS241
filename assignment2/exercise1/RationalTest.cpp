//
// Created by Bugen Zhao on 2019/9/19.
//

#include "Rational.h"
#include <vector>
#include <sstream>
#include <tuple>

using namespace std;

using Poly = vector<Rational>;

tuple<Poly, Poly> divide(Poly dividend, Poly divisor) {
    auto getM = [](const Poly &poly) {
        auto pos = find_if(poly.begin(), poly.end(), [](Rational x) { return x != Rational::ZERO; });
        return distance(pos, poly.end()) - 1;
    };
    int m = getM(dividend),
            n = getM(divisor);
    cout << m << ' ' << n << endl;

    Poly ans(m - n);
    for (int i = m - n; i >= 0; --i) {
        ans[i] = dividend[i + n] / divisor[n];
        for (int j = n; j >= 0; --j) {
            dividend[i + j] = dividend[i + j] - ans[i] * divisor[i];
        }
    }

    for (auto i:ans)
        cout << i << ' ';

    return {{},
            {}};
}

int main() {
    Poly dividend(4), divisor(4);

    try {
        int tmp = 0;
        for (int i = 0; i < 4; ++i) {
            cin >> tmp;
            if (cin.fail() || (i == 0 && tmp == 0)) {
                throw runtime_error("");
            }
            dividend[i] = Rational(tmp);
        }
        for (int i = 0; i < 4; ++i) {
            cin >> tmp;
            if (cin.fail()) {
                throw runtime_error("");
            }
            divisor[i] = Rational(tmp);
        }
    } catch (const exception &e) {
        cerr << "error" << endl;
        return -1;
    }

    divide(dividend, divisor);
}