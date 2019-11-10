//
// Created by Bugen Zhao on 2019/11/10.
//

#ifndef CS241_POPULATION_HPP
#define CS241_POPULATION_HPP

#include <vector>
#include <functional>
#include <random>
#include <algorithm>

using std::vector, std::function;

template<typename Chromosome>
class Population {
private:
    vector<Chromosome> population;
    using dataType=typename Chromosome::value_type;
    function<double(Chromosome)> getFitness;
    function<dataType(dataType)> doMutation;
    std::mt19937 gen;
    const int chromosomeSize;
    bool ok;
    double lastAvgFitness;

public:
    Population(const vector<Chromosome> &population,
               const function<double(Chromosome)> &fitnessFunction,
               const function<dataType(dataType)> &mutationFunction) :
            population(population),
            getFitness(fitnessFunction),
            doMutation(mutationFunction),
            gen(std::random_device()()),
            chromosomeSize(population[0].size()),
            ok(false),
            lastAvgFitness(INFINITY) {}

    void crossover(double pc) {
        vector<int> updateIndex(population.size());
        std::uniform_int_distribution<> dis(0, chromosomeSize - 1);

        for (int i = 0; i < population.size(); ++i) {
            updateIndex[i] = i;
        }
        std::shuffle(updateIndex.begin(), updateIndex.end(), gen);
        updateIndex.resize(int(pc * population.size()) / 2 * 2);
        for (int i = 0; i < updateIndex.size(); i += 2) {
            auto &a = population[updateIndex[i]];
            auto &b = population[updateIndex[i + 1]];
            int pos1 = dis(gen);
            int pos2 = dis(gen);
            for (int j = pos1; j < pos2; ++j) {
                std::swap(a[j], b[j]);
            }
        }
    }

    void mutation(double pm) {
        vector<int> updateIndex(population.size());
        std::uniform_int_distribution<> dis1(0, population.size() - 1);
        std::uniform_int_distribution<> dis2(0, chromosomeSize - 1);

        int times = chromosomeSize * population.size() * pm;
        for (int i = 0; i < times; ++i) {
            int m = dis1(gen);
            int n = dis2(gen);
            population[m][n] = doMutation(population[m][n]);
        }
    }

    void update() {
        vector<double> fitness(population.size());
        for (int i = 0; i < population.size(); ++i) {
            fitness[i] = getFitness(population[i]);
        }

        double avgFitness = std::accumulate(fitness.begin(), fitness.end(), 0.0) / population.size();
        if (abs(avgFitness - lastAvgFitness) < 1e-3) ok = true;
        lastAvgFitness = avgFitness;

        double minFitness = *std::min_element(fitness.begin(), fitness.end());
        if (minFitness < 0) throw std::runtime_error("update: negative fitness value");
        for (int i = 0; i < population.size(); ++i) {
            fitness[i] -= minFitness;
        }

        vector<double> cumFitness(population.size());
        cumFitness[0] = fitness[0];
        for (int i = 1; i < population.size(); ++i) {
            cumFitness[i] = cumFitness[i - 1] + getFitness(population[i]);
        }
        std::uniform_real_distribution<> dis(0.0, cumFitness[population.size() - 1]);

        vector<Chromosome> newPopulation;
        newPopulation.reserve(population.size());
        for (int i = 0; i < population.size(); ++i) {
            int pos = 0;
            do {
                double real = dis(gen);
                pos = std::lower_bound(cumFitness.begin(), cumFitness.end(), real) - cumFitness.begin();
            } while (pos == population.size());
            newPopulation.push_back(population[pos]);
        }

        population = newPopulation;
    }

    const vector<Chromosome> &get() const {
        return population;
    }

    vector<Chromosome> getSorted() const {
        vector<Chromosome> result(population.cbegin(), population.cend());
        std::sort(result.begin(), result.end(),
                  [this](const Chromosome &a, const Chromosome &b) {
                      return getFitness(a) > getFitness(b);
                  });
        return result;
    }

    Chromosome getOptimal() const {
        return *std::max_element(population.begin(), population.end(),
                                 [this](const Chromosome &a, const Chromosome &b) {
                                     return getFitness(a) < getFitness(b);
                                 });
    }

    bool isOk() const {
        return ok;
    }
};


#endif //CS241_POPULATION_HPP
