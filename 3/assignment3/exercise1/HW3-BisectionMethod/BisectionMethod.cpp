//
// Created by Bugen Zhao on 2019/9/26.
//

#include <iostream>

using std::cout, std::endl;

auto f = [](double x) { return 10.0 * x * x * x - 8.3 * x * x + 2.295 * x - 0.21141; };
auto sgn = [](double x) { return x > 0.0; };

double get_root_b(double a, double b) {
    double m = 0.0;
    unsigned i = 0U;
    while (b - a > 1e-5) {
        m = a + (b - a) / 2.0;
        cout << 'x' << i++ << ": " << m << endl;
        if (sgn(f(a)) ^ sgn(f(m))) b = m;
        else a = m;
    }
    return m;
}

int main() {
    get_root_b(0.28516, 0.400912);
    return 0;
}