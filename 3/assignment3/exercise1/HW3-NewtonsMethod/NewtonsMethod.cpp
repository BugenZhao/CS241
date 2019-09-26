//
// Created by Bugen Zhao on 2019/9/26.
//

#include <iostream>
#include <cmath>

using std::cout, std::endl;

auto f = [](double x) { return 10.0 * x * x * x - 8.3 * x * x + 2.295 * x - 0.21141; };
auto fd = [](double x) { return 30.0 * x * x - 16.6 * x + 2.295; };

double get_root_n(double x) {
    unsigned i = 0U;
    double x_new = x;
    do {
        x = x_new;
        x_new = x - f(x) / fd(x);
        cout << 'x' << i++ << ": " << x << endl;
    } while (fabs(x - x_new) > 1e-5);
    return x;
}

int main() {
    get_root_n(0.343036);
    return 0;
}