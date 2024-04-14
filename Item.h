#ifndef UNTITLED1_ITEM_H
#define UNTITLED1_ITEM_H


class Item {

    friend class CKnapsackProblem;

private:

    float value;
    float weight;

public:

    Item(Item &&other) = default;

    Item(const Item &other) = default;

    ~Item() = default;

    Item &operator=(const Item &other) = default;

    Item &operator=(Item &&other) = default;


    Item(float value, float weight);

    float getValue() const;

    float getWeight() const;
};


#endif //UNTITLED1_ITEM_H
