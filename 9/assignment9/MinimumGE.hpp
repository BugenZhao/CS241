//
// Created by Bugen Zhao on 2019/11/10.
//

#ifndef CS241_MINIMUMGE_HPP
#define CS241_MINIMUMGE_HPP

#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using std::vector;

namespace MinimumGE {
    auto func = [](double x) -> double { return x * sin(x); };

    constexpr unsigned SIZE = 16;
    const double lower = -1.0;
    const double upper = 15.0;

    std::mt19937 gen((std::random_device()()));

    typedef vector<bool> Bits;

    Bits encode(double x) {
        if (x < lower || x > upper) throw std::invalid_argument("");
        auto t = static_cast<unsigned>((x - lower) * ((1u << SIZE) - 1U) / (upper - lower));
        std::bitset<SIZE> tmp((t));

        Bits result;
        for (int i = 0; i < SIZE; ++i) {
            result.push_back(tmp[i]);
        }
        return result;
    }

    double decode(const Bits &bits) {
        unsigned t = std::accumulate(bits.rbegin(), bits.rend(), 0u,
                                     [](unsigned x, unsigned y) { return (x << 1u) + y; });
        return (t + 0.0) * (upper - lower) / ((1u << SIZE) - 1U) + lower;
    }

    auto fitnessFunction = [](const Bits &bits) -> double {
        return -func(decode(bits)) + 15.0;
    };

    auto mutationFunction = [](bool bit) -> bool {
        return ~bit;
    };

    Bits getRandom() {
        std::uniform_real_distribution<> dis(lower, upper);
        return encode(dis(gen));
    }

    constexpr int N = 3000;
}

#endif //CS241_MINIMUMGE_HPP
