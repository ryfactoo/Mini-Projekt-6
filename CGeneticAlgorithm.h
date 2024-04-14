#ifndef UNTITLED1_CGENETICALGORITHM_H
#define UNTITLED1_CGENETICALGORITHM_H
#include "CKnapsackProblem.h"
#include <vector>
#include <random>


class CGeneticAlgorithm {


private:

    float mutProb;

    float crossProb;

    float addGenInFirstPopulationProb;

    int popSize;

    std::vector<bool> bestGen;


    std::vector<CIndividual> makePopulation(CKnapsackProblem& cKnapsackProblem,std::mt19937 randEngine);

    std::vector<CIndividual>
    algorytmAG(const CKnapsackProblem &cKnapsackProblem, int repeat, std::vector<CIndividual> population,
               std::mt19937 &randEngine);

    int getParent(std::vector<CIndividual> population, int secondParent,const CKnapsackProblem &cKnapsackProblem,
                  std::mt19937 &randEngine);


public:

    CGeneticAlgorithm(CGeneticAlgorithm &&other) = default;

    CGeneticAlgorithm(const CGeneticAlgorithm &other) = default;

    ~CGeneticAlgorithm() = default;

    CGeneticAlgorithm &operator=(const CGeneticAlgorithm &other) = default;

    CGeneticAlgorithm &operator=(CGeneticAlgorithm &&other) = default;



    bool checkConfiguration();

    CGeneticAlgorithm(float mutProb,float crossProb,float addGenInFirstPopulationProb,int popSize);

    void runAG(CKnapsackProblem& cKnapsackProblem,int repeat);

    const std::vector<bool> &getBestGen() const;

};


#endif //UNTITLED1_CGENETICALGORITHM_H
