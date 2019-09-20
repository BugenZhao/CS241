//
// Created by Bugen Zhao on 2019/9/19.
//

#include "Rational.h"
#include <vector>
#include <sstream>

using namespace std;

using Poly = vector<Rational>;

vector<Poly> divide(Poly dividend, Poly divisor) {
    auto get = [](const Poly &poly) {
        auto pos = find_if(poly.rbegin(), poly.rend(), [](Rational x) { return x != Rational::ZERO; });
        return distance(pos, poly.rend()) - 1;
    };
    int m = get(dividend), n = get(divisor);

    Poly quotient(m - n + 1);
    for (int i = m - n; i >= 0; --i) {
        quotient[i] = dividend[i + n] / divisor[n];
        for (int j = n; j >= 0; --j) {
            dividend[i + j] = dividend[i + j] - quotient[i] * divisor[j];
        }
    }

    return {quotient, dividend};
}

int main() {
    constexpr int m = 4, n = 4;
    Poly dividend(m), divisor(n);

    try {
        int tmp = 0;
        for (int i = 0; i < m; ++i) {
            cin >> tmp;
            if (cin.fail() || (i == 0 && tmp == 0)) {
                throw runtime_error("");
            }
            dividend[m - 1 - i] = Rational(tmp);
        }
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            if (cin.fail()) {
                throw runtime_error("");
            }
            divisor[n - 1 - i] = Rational(tmp);
        }
    } catch (const exception &e) {
        cerr << "error" << endl;
        return -1;
    }

    auto answers = divide(dividend, divisor);
    for (const auto &ans:answers) {
        bool flag = false;
        for (auto it = ans.rbegin(); it != ans.rend(); ++it)
            if (flag || *it != Rational::ZERO) {
                flag = true;
                cout << *it << ' ';
            }
        if (!flag) cout << 0;
        cout << endl;
    }

    return 0;
}