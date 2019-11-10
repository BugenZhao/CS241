//
// Created by Bugen Zhao on 2019/11/10.
//

#ifndef CS241_GE_HPP
#define CS241_GE_HPP


#include "Population.hpp"

template<typename Chromosome>
class GE {
private:
    Population<Chromosome> population;
    const double pc;
    const double pm;
public:
    explicit GE(const Population<Chromosome> &initial,
                double pc=0.8,
                double pm=0.01) :
            population(initial),
            pc(pc), pm(pm) {}

    void run(int times = 1) {
        for (int i = 0; i < times; ++i) {
            population.crossover(pc);
            population.mutation(pm);
            population.update();
        }
    }

    const Population<Chromosome> &getPopulation() const {
        return population;
    }
};


#endif //CS241_GE_HPP
