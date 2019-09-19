//
// Created by Bugen Zhao on 2019/9/19.
//

#ifndef CS241_RATIONAL_H
#define CS241_RATIONAL_H


#include <iostream>
#include <cmath>

class Rational {
    int num;
    int den;

    void reduceFraction();

    bool isInteger() const;

    static int gcd(int a, int b);

public:
    Rational(int num, int den);

    explicit Rational(int i);

    Rational();

    int getNum() const;

    int getDen() const;

    friend std::ostream &operator<<(std::ostream &os, const Rational &rational);

    friend std::istream &operator>>(std::istream &in, Rational &rational);

    bool operator==(const Rational &rhs) const;

    bool operator!=(const Rational &rhs) const;

    bool operator<(const Rational &rhs) const;

    bool operator>(const Rational &rhs) const;

    bool operator<=(const Rational &rhs) const;

    bool operator>=(const Rational &rhs) const;

    Rational operator+(const Rational &rhs) const;

    Rational operator-(const Rational &rhs) const;

    Rational operator-() const;

    Rational operator*(const Rational &rhs) const;

    Rational operator/(const Rational &rhs) const;

    Rational reciprocal() const;

    const static Rational ZERO;

    explicit operator double() const;

    explicit operator int() const;

};


#endif //CS241_RATIONAL_H
