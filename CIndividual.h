#ifndef UNTITLED1_CINDIVIDUAL_H
#define UNTITLED1_CINDIVIDUAL_H
#include "CKnapsackProblem.h"
#include "Item.h"
#include <vector>
#include <random>

class CKnapsackProblem;

class CIndividual {

private:


    std::vector<bool> genotype;

    float fitness;

    CIndividual(CIndividual parent1,CIndividual parent2,int pointCross,const CKnapsackProblem& cKnapsackProblem);


public:

    CIndividual(CIndividual &&other) = default;

    CIndividual(const CIndividual &other) = default;

    ~CIndividual() = default;

    CIndividual &operator=(const CIndividual &other) = default;

    CIndividual &operator=(CIndividual &&other) = default;



    CIndividual(std::vector<bool> &genotyp,const CKnapsackProblem &cKnapsackProblem);

    CIndividual(const CKnapsackProblem& cKnapsackProblem);

    float getFitness(const CKnapsackProblem& cKnapsackProblem);

    const std::vector<bool> &getGenotyp() const;

    void randomGen(const CKnapsackProblem &cKnapsackProblem,std::mt19937 &randEngine,float addGenInFirstPopulationProb);

    std::vector<CIndividual> cross(const CKnapsackProblem &cKnapsackProblem, float crossProb, CIndividual &cIndividualOther, std::mt19937 &randEngine);

    void mutations(const CKnapsackProblem &cKnapsackProblem, float mutProb, std::mt19937 &randEngine);
};


#endif //UNTITLED1_CINDIVIDUAL_H
