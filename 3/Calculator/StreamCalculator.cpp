//
// Created by Bugen Zhao on 2019/9/27.
//

#include "StreamCalculator.h"

StreamCalculator::StreamCalculator(std::basic_istream<char> &in) : in(in), ts(in) {}

double StreamCalculator::expression() {
    double left = term();
    while (true) {
        Token token = ts.get();
        switch (token.kind) {
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

double StreamCalculator::primary() {
    Token token = ts.get();
    switch (token.kind) {
        case '(': {
            double d = expression();
            token = ts.get();
            if (token.kind != ')') throw std::runtime_error(") expected.");
            return d;
        }
        case Token::NUMBER:
            return token.value;
        case '+':
            return ts.get().value;
        case '-':
            return -ts.get().value;
        default:
            throw std::runtime_error("Primary expected.");
    }
}

double StreamCalculator::term() {
    double left = primary();
    while (true) {
        Token token = ts.get();
        switch (token.kind) {
            case '*':
                left *= primary();
                break;
            case '/':
                left /= primary();
                break;
            case '%':
                throw std::runtime_error("Unsupported operator %");
                break;
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
        switch (token.kind) {
            case ';':
                return val;
            default: {
                ts.putback(token);
                val = expression();
            }
        }
    }
    return 0.0;
}

