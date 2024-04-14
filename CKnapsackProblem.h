#ifndef UNTITLED1_CKNAPSACKPROBLEM_H
#define UNTITLED1_CKNAPSACKPROBLEM_H
#include "Item.h"
#include "CIndividual.h"
#include <fstream>
#include <string>
#include <vector>


class CKnapsackProblem {

    friend class CIndividual;

private:

    std::vector<Item> items;

    int itemsSize;

    float backpackSize;

public:

    CKnapsackProblem(CKnapsackProblem &&other) = default;

    CKnapsackProblem(const CKnapsackProblem &other) = default;

    ~CKnapsackProblem() = default;

    CKnapsackProblem &operator=(const CKnapsackProblem &other) = default;

    CKnapsackProblem &operator=(CKnapsackProblem &&other) = default;


    CKnapsackProblem(std::string string);

    bool setBackpackSize(float backpackSize);

    bool setItemValue(int position,float value);

    bool setItemWeight(int position,float weight);

    bool loadItems(std::string filePath);

    float getBackpackSize() const;

    bool checkConfiguration();

    float calculateFitness( std::vector<bool> genotyp) const;

};


#endif //UNTITLED1_CKNAPSACKPROBLEM_H
