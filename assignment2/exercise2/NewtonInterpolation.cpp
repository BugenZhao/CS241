//
// Created by Bugen Zhao on 2019/9/19.
//

#include "NewtonInterpolation.h"

NewtonInterpolation::NewtonInterpolation() : difference(COUNT) {}

void NewtonInterpolation::DividedDifferenceTable(std::ostream &os) {
    for (int r = 0; r < COUNT; ++r) {
        difference[r].push_back(fx[r]);
        for (int c = 1; c <= r; ++c) {
            difference[r].push_back((difference[r][c - 1] - difference[r - 1][c - 1]) / (x[r] - x[r - c]));
        }
    }

    for (int r = 0; r < COUNT; ++r) {
        for (int c = 0; c <= r; ++c) {
            os.width(9);
            os << difference[r][c] << '\t';
        }
        os << '\n';
    }
}

double NewtonInterpolation::ApproximateValue(double xNew) {
    double ans = difference[0][0];
    double s = 1;
    for (int i = 1; i < COUNT; ++i) {
        s *= xNew - x[i - 1];
        ans += difference[i][i] * s;
    }
    return ans;
}
