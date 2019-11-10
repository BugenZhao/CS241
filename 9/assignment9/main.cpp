#include "GE.hpp"
#include "StringGE.hpp"
#include "MinimumGE.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int exercise1() {
    vector<string> v;
    v.reserve(StringGE::N);
    for (int i = 0; i < StringGE::N; ++i) {
        v.push_back(StringGE::getRandom());
    }

    Population<string> initial(v,
                               StringGE::fitnessFunction,
                               StringGE::mutationFunction);
    GE<string> ge(initial);

    for (int i = 0; i < 5000; ++i) {
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

int exercise2() {
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

    for (int i = 0; i < 5000; ++i) {
        ge.run();
        auto optimal = ge.getPopulation().getOptimal();
        cout << "Generation " << setw(4) << i + 1
             << "    Answer: " << MinimumGE::decode(optimal) << endl;
        if (ge.getPopulation().isOk()) {
            cout << "Done." << endl;
            break;
        }
    }

    return -1;
}


int main() {
    cout << "[EXERCISE 1]" << endl;
    exercise1();
    cout << "\n\n\n" << "[EXERCISE 2]" << endl;
    exercise2();
}