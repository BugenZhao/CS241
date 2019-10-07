//
// Created by Bugen Zhao on 2019/9/27.
//

#include "StreamCalculator.h"

StreamCalculator::StreamCalculator(std::basic_istream<char> &in) : in(in), ts(in) {}

double StreamCalculator::expr() {
    double left = term();
    while (true) {
        Token token = ts.get();
        switch (token.kind()) {
            case '+':
                left += term();
                break;
            case '-':
                left -= term();
                break;
            default: {
                ts.putback(token);
                return left;
            }
        }
    }
}

double StreamCalculator::factor() {
    Token token = ts.get();
    switch (token.kind()) {
        case '(': {
            double d = expr();
            token = ts.get();
            if (token.kind() != ')') throw std::runtime_error(") expected.");
            return d;
        }
        case Token::NUMBER:
            return token.value();
        case '+':
            return ts.get().value();
        case '-':
            return -ts.get().value();
        default:
            throw std::runtime_error("Primary expected.");
    }
}

double StreamCalculator::term() {
    double left = factor();
    while (true) {
        Token token = ts.get();
        switch (token.kind()) {
            case '*':
                left *= factor();
                break;
            case '/': {
                double d = factor();
                if (d == 0) throw std::runtime_error("Division by zero");
                left /= d;
                break;
            }
            case '%':
                throw std::runtime_error("Unsupported operator %");
            default: {
                ts.putback(token);
                return left;
            }
        }
    }
}

double StreamCalculator::calculate() {
    double val = 0.0;
    while (in) {
        Token token = ts.get();
        switch (token.kind()) {
            case ';':
                return val;
            default: {
                ts.putback(token);
                val = expr();
            }
        }
    }
    return 0.0;
}

