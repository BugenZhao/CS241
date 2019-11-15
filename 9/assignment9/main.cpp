#include "GE.hpp"
#include "StringGE.hpp"
#include "MinimumGE.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int exercise1(int maxIterTimes = 5000) {
    vector<string> v;
    v.reserve(StringGE::N);
    for (int i = 0; i < StringGE::N; ++i) {
        v.push_back(StringGE::getRandom());
    }

    Population<string> initial(v,
                               StringGE::fitnessFunction,
                               StringGE::mutationFunction);
    GE<string> ge(initial);

    for (int i = 0; i < maxIterTimes; ++i) {
        ge.run();
        auto optimal = ge.getPopulation().getOptimal();
        cout << "Generation " << setw(4) << i + 1
             << "    String: " << optimal << endl;
        if (optimal == StringGE::TARGET) {
            cout << "Done." << endl;
            break;
        }
    }

    return -1;
}

double exercise2(int maxIterTimes = 5000, bool p = true) {
    using MinimumGE::Bits;
    vector<Bits> v;
    v.reserve(MinimumGE::N);
    for (int i = 0; i < MinimumGE::N; ++i) {
        v.push_back(MinimumGE::getRandom());
    }

    Population<Bits> initial(v,
                             MinimumGE::fitnessFunction,
                             MinimumGE::mutationFunction);
    GE<Bits> ge(initial, 0.8, 0.002);

    for (int i = 0; i < maxIterTimes; ++i) {
        ge.run();
        auto optimal = MinimumGE::decode(ge.getPopulation().getOptimal());
        if (p)
            cout << "Generation " << setw(4) << i + 1
                 << "    Answer: " << optimal << endl;
        if (ge.getPopulation().isOk()) {
            cout << "Done." << endl;
            return optimal;
        }
    }

    return -1;
}

void test() {
    int N = 100;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        auto ans = exercise2(200, false);
        count += (ans >= 11.08 && ans <= 11.10);
    }
    cout << count << "/" << N << endl;  // 96/100
}

int main() {
    cout << "[EXERCISE 1]" << endl;
    exercise1();
    cout << "\n\n\n" << "[EXERCISE 2]" << endl;
    exercise2();
}