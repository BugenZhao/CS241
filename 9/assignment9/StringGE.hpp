//
// Created by Bugen Zhao on 2019/11/10.
//

#ifndef CS241_STRINGGE_HPP
#define CS241_STRINGGE_HPP

#include <string>
#include <random>

using std::string;

namespace StringGE {
    const string GENES =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ" \
            "abcdefghijklmnopqrstuvwxyz 1234567890 , .-;: !\"#%&/()=?@${[]}";
    const string TARGET =
            "Hello, World! 19/11/09";

    std::mt19937 gen((std::random_device()()));
    std::uniform_int_distribution<> dis(0, GENES.size() - 1);

    auto fitnessFunction = [](const string &str) -> int {
        if (str.size() != TARGET.size()) throw std::invalid_argument("fitness: wrong string length");
        int result = 0;
        for (int i = 0; i < TARGET.size(); ++i) {
            result += str[i] == TARGET[i];
        }
        return result;
    };

    auto mutationFunction = [](char) -> char {
        return GENES[dis(gen)];
    };

    string getRandom() {
        string result(TARGET.size(), ' ');
        for (int i = 0; i < TARGET.size(); ++i) {
            result[i] = GENES[dis(gen)];
        }
        return result;
    }

    constexpr int N = 1000;
}

#endif //CS241_STRINGGE_HPP
