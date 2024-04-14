#include "CGeneticAlgorithm.h"
#include <algorithm>

CGeneticAlgorithm::CGeneticAlgorithm(float mutProb, float crossProb,float addGenInFirstPopulationProb, int popSize)
: mutProb(mutProb),
crossProb(crossProb),
popSize(popSize),
bestGen(std::vector<bool>()),
addGenInFirstPopulationProb(addGenInFirstPopulationProb){
}



std::vector<CIndividual> CGeneticAlgorithm::makePopulation(CKnapsackProblem& cKnapsackProblem,std::mt19937 randEngine){

    std::vector<CIndividual> population;

    for (int i = 0; i < popSize; i++) {
        CIndividual newCIndividual(cKnapsackProblem);
        newCIndividual.randomGen(cKnapsackProblem,randEngine, addGenInFirstPopulationProb);
        population.push_back(newCIndividual);
    }

    return population;
}

void CGeneticAlgorithm::runAG(CKnapsackProblem& cKnapsackProblem,int repeat){

    if (!checkConfiguration() || !cKnapsackProblem.checkConfiguration()){
        throw std::invalid_argument ("Check configuration");
    }

    std::mt19937 randEngine(std::random_device{}());

    std::vector<CIndividual> population =  makePopulation(cKnapsackProblem,randEngine);

    population = CGeneticAlgorithm::algorytmAG(cKnapsackProblem,repeat,population,randEngine);


    CIndividual bestIndividual = population[0];

    for (int i = 1; i < popSize; ++i) {
        if (bestIndividual.getFitness(cKnapsackProblem) < population[i].getFitness(cKnapsackProblem)){
            bestIndividual = population[i];
        }
    }

    bestGen = bestIndividual.getGenotyp();
}

std::vector<CIndividual> CGeneticAlgorithm::algorytmAG(const CKnapsackProblem& cKnapsackProblem,int repeat,std::vector<CIndividual> population,std::mt19937 &randEngine){



    for (int i = 0; i < repeat; ++i) {

        std::vector<CIndividual> childPopulation;


        for (int j = 0; j < popSize/2 +1; ++j) {

            int parentFirst = getParent(population,-1,cKnapsackProblem,randEngine);

            std::vector<CIndividual> tep = population[parentFirst].cross(cKnapsackProblem, crossProb,
                                                                         population[getParent(population,
                                                                                              parentFirst,cKnapsackProblem,randEngine)],randEngine);


            if (j == popSize / 2 && popSize % 2 == 1) {
                childPopulation.push_back(tep[0]);
            } else {
                childPopulation.insert(childPopulation.end(), tep.begin(), tep.end());
            }
        }

        for (int j = 0; j < popSize; ++j) {
            childPopulation[j].mutations(cKnapsackProblem,mutProb,randEngine);
        }

        population.clear();
        population = childPopulation;
    }


    return population;
}

int CGeneticAlgorithm::getParent(std::vector<CIndividual> population,int secondParent,const CKnapsackProblem& cKnapsackProblem,std::mt19937 &randEngine){

    std::uniform_int_distribution<> distribution(0,popSize-1);

    std::vector<int> potencalParent;
    int index;

    while (potencalParent.size() < 4 && population.size() - 1 >= potencalParent.size()){

        while (secondParent == (index = distribution(randEngine)));

        for (int i = 0; i < potencalParent.size(); i++) {
            if (index == potencalParent[i]){
                i=-1;
                index =  distribution(randEngine);
            }
        }

        potencalParent.push_back(index);
    }

    int bestParent = potencalParent[0];

    for (int i = 1; i < potencalParent.size(); ++i) {
        if (population[bestParent].getFitness(cKnapsackProblem)< population[potencalParent[i]].getFitness(cKnapsackProblem)){
            bestParent = potencalParent[i];
        }
    }

    return bestParent;
}


bool CGeneticAlgorithm::checkConfiguration(){
    if (mutProb >= 0 && mutProb <= 1 &&  crossProb >= 0 && crossProb <= 1 && popSize > 0 && addGenInFirstPopulationProb >= 0 && addGenInFirstPopulationProb <= 1) return true;
    return false;
}

const std::vector<bool> &CGeneticAlgorithm::getBestGen() const {
    return bestGen;
}


