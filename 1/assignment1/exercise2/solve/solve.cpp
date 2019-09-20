#include "solve.h"

vector<double> solve(double a, double b, double c) {
    double delta = b * b - 4 * a * c;
    if (delta < 0) throw runtime_error("Nope!");
    double x1 = (-b + sqrt(delta)) / (2 * a);
    double x2 = (-b - sqrt(delta)) / (2 * a);
    return vector<double>{x1, x2};
}
