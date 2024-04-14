
#include "Item.h"

Item::Item(float value, float weight) : value(value), weight(weight) {}

float Item::getValue() const {
    return value;
}

float Item::getWeight() const {
    return weight;
}



