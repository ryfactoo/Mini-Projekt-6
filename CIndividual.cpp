#include "CIndividual.h"
#include <random>

CIndividual::CIndividual(std::vector<bool> &genotyp,const CKnapsackProblem& cKnapsackProblem)
        : genotype(genotyp),
          fitness(-1){
}

CIndividual::CIndividual(const CKnapsackProblem& cKnapsackProblem)
:fitness(-1)
{
    genotype.reserve(cKnapsackProblem.itemsSize);
}

CIndividual::CIndividual(CIndividual parent1,CIndividual parent2,int pointCross,const CKnapsackProblem& cKnapsackProblem)
:fitness(-1){
    genotype.reserve(cKnapsackProblem.itemsSize);

    for (int i = 0; i < parent1.genotype.size(); ++i) {
        if (i <= pointCross) genotype.push_back(parent1.genotype[i]);
        else genotype.push_back(parent2.genotype[i]);
    }
}



void CIndividual::randomGen (const CKnapsackProblem& cKnapsackProblem,std::mt19937& randEngine,float addGenInFirstPopulationProb){

    std::uniform_real_distribution<> distribution(0,1);

    for (int i = 0; i < cKnapsackProblem.itemsSize; i++) {
        genotype.push_back(distribution(randEngine) <= addGenInFirstPopulationProb);
    }

    fitness = -1;
}

float CIndividual::getFitness(const CKnapsackProblem& cKnapsackProblem) {

    if (fitness == -1){
        fitness = cKnapsackProblem.calculateFitness(genotype);
    }

    return fitness;
}


std::vector<CIndividual> CIndividual::cross (const CKnapsackProblem& cKnapsackProblem,float crossProb,CIndividual& cIndividualOther,std::mt19937& randEngine){

    std::vector<CIndividual> child;
    std::uniform_real_distribution<> distribution(0,1);
    std::uniform_int_distribution<> distributionInt(0,cKnapsackProblem.itemsSize );


    if (distribution(randEngine) <= crossProb){

        int pointCross = distributionInt(randEngine);
        child.push_back(CIndividual(*this,cIndividualOther,pointCross,cKnapsackProblem));
        child.push_back(CIndividual(cIndividualOther,*this,pointCross,cKnapsackProblem));

    } else {
        child.push_back(cIndividualOther);
        child.push_back(*this);
    }

    return child;
}



void CIndividual::mutations (const CKnapsackProblem& cKnapsackProblem,float mutProb,std::mt19937& randEngine){

    std::uniform_real_distribution<> distribution(0,1);

    for (int i = 0; i < genotype.size(); i++) {
        if (distribution(randEngine) <= mutProb ){
            genotype[i] = !genotype[i];
        }
    }

    fitness = -1;
}

const std::vector<bool> &CIndividual::getGenotyp() const {
    return genotype;
}



