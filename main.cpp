#include <iostream>
#include "CGeneticAlgorithm.h"
#include "CKnapsackProblem.h"
#include <bits/stdc++.h>


int main() {

    CKnapsackProblem cKnapsackProblem(R"(D:\Studia\3 semsetr\TEP\Mini-Projekt 6\items.txt)");
    CGeneticAlgorithm cGeneticAlgorithm(0.005,0.001,0.002,20);

    cGeneticAlgorithm.runAG(cKnapsackProblem,5000);
    float kot = cKnapsackProblem.calculateFitness(cGeneticAlgorithm.getBestGen());
    std::cout << kot << std::endl;



    return 0;
}
