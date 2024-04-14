#include <bits/stdc++.h>
#include "CKnapsackProblem.h"
#include "InvalidValueInFile.h"

CKnapsackProblem::CKnapsackProblem(std::string string){
    this->loadItems(string);
}



bool CKnapsackProblem::setBackpackSize(float backpackSize){
    if (backpackSize >= 0) {
        this->backpackSize = backpackSize;
        return true;

    } return false;

}


bool CKnapsackProblem::setItemValue(int position,float value){
    if (value >= 0 && position < itemsSize){
        items[position].value = value;
        return true;

    } return false;

}


bool CKnapsackProblem::setItemWeight(int position,float weight){
    if (weight >= 0 && position < itemsSize){
        items[position].weight = weight;
        return true;

    } return false;
}

float CKnapsackProblem::getBackpackSize() const {
    return backpackSize;
}



bool CKnapsackProblem::loadItems(std::string fileName){

    std::string line;
    std::ifstream file (fileName);
    if (file.is_open()){

        float value;
        float weight;

        getline (file, line);

        std::istringstream istringstream(line);

        istringstream >> value;

        if (value <= 0 || !istringstream.eof()){
            throw InvalidValueInFile("error backpack size: " + line);
        }

        backpackSize = value;

        while ( getline (file, line) )
        {
            if (line != "") {

                weight = 0;
                value = 0;

                istringstream.clear();
                istringstream.str(line);


                istringstream >> value >> weight;

                if (value<=0 || weight <= 0 || !istringstream.eof()){
                    throw InvalidValueInFile(line);
                }

                items.push_back(Item(value, weight));
                itemsSize++;


                }


            }
    } else throw InvalidValueInFile("wrong path To File");
}


bool CKnapsackProblem::checkConfiguration(){
    if (backpackSize >= 0 && itemsSize > 0) return true;
    return false;
}


float CKnapsackProblem::calculateFitness(std::vector<bool> genotyp) const{
    float weightIndividual = 0;
    float valueIndividual = 0;


    for (int i = 0; i < itemsSize ; i++) {

        if (genotyp[i]){
            weightIndividual += items[i].getWeight();
            valueIndividual += items[i].getValue();
        }
    }

    if (weightIndividual<= backpackSize){
        return valueIndividual;
    }else{
        return 0;
    }
}

