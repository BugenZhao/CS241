//
// Created by Bugen Zhao on 2019/9/19.
//

#ifndef CS241_NEWTONINTERPOLATION_H
#define CS241_NEWTONINTERPOLATION_H

#include <vector>
#include <iostream>
#include<iomanip>


class NewtonInterpolation {
    static constexpr int COUNT = 7;
    const double x[COUNT] = {0.1, 0.4, 1.0, 1.8, 2.9, 3.2, 3.8};
    const double fx[COUNT] = {4.2, 3.8, 2.5, 2.0, -2.0, 0.0, -0.3};
//    static constexpr int COUNT = 4;
//    const double x[COUNT] = {0, 1, 2, 3};
//    const double fx[COUNT] = {1, 2, 4, 8};

    std::vector<std::vector<double>> difference;

public:
    NewtonInterpolation();

    void DividedDifferenceTable(std::ostream &os = std::cout);

    double ApproximateValue(double xNew);
};


#endif //CS241_NEWTONINTERPOLATION_H
