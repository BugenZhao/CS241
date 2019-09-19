//
// Created by Bugen Zhao on 2019/9/19.
//

#include "Rational.h"

Rational::Rational(int num, int den) : num(num), den(den) {
    reduceFraction();
}

int Rational::getNum() const {
    return num;
}

int Rational::getDen() const {
    return den;
}

std::ostream &operator<<(std::ostream &os, const Rational &rational) {
    if (rational.isInteger()) os << rational.num;
    else os << rational.num << '/' << rational.den;
    return os;
}

const Rational Rational::ZERO = Rational(0, 1);

std::istream &operator>>(std::istream &in, Rational &rational) {
    in >> rational.num >> rational.den;
    rational.reduceFraction();
    return in;
}

bool Rational::operator==(const Rational &rhs) const {
    return num == rhs.num &&
           den == rhs.den;
}

bool Rational::operator!=(const Rational &rhs) const {
    return !(rhs == *this);
}

bool Rational::operator<(const Rational &rhs) const {
    int m = den / gcd(den, rhs.den) * rhs.den;
    int n1 = num * (m / den);
    int n2 = rhs.num * (m / rhs.den);
    return n1 < n2;
}

bool Rational::operator>(const Rational &rhs) const {
    return rhs < *this;
}

bool Rational::operator<=(const Rational &rhs) const {
    return !(rhs < *this);
}

bool Rational::operator>=(const Rational &rhs) const {
    return !(*this < rhs);
}

void Rational::reduceFraction() {
    if (num == 0) {
        den = 1;
        return;
    }
    int d = gcd(abs(num), abs(den));
    if ((num < 0 && den < 0) || (num > 0 && den < 0))
        num = -num, den = -den;
    num /= d, den /= d;
}

Rational Rational::operator+(const Rational &rhs) const {
    int m = den / gcd(den, rhs.den) * rhs.den;
    int n1 = num * (m / den);
    int n2 = rhs.num * (m / rhs.den);
    return Rational(n1 + n2, m);
}

Rational Rational::operator-(const Rational &rhs) const {
    int m = den / gcd(den, rhs.den) * rhs.den;
    int n1 = num * (m / den);
    int n2 = rhs.num * (m / rhs.den);
    return Rational(n1 - n2, m);
}

int Rational::gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

Rational::Rational() : Rational(0, 1) {}

bool Rational::isInteger() const {
    return den == 1;
}

Rational Rational::operator*(const Rational &rhs) const {
    Rational p(num, rhs.den);
    Rational q(rhs.num, den);
    return Rational(p.num * q.num, p.den * q.den);
}

Rational Rational::operator/(const Rational &rhs) const {
    return *this * rhs.reciprocal();
}

Rational Rational::reciprocal() const {
    return Rational(den, num);
}

Rational Rational::operator-() const {
    return ZERO - *this;
}

Rational::Rational(int i) : num(i), den(1) {}

Rational::operator double() const {
    return (num + 0.0) / den;
}

Rational::operator int() const {
    return num / den;
}


