#pragma once
#include "Mutator.h"

class BitFlipProb: public Mutator{
private:
    double prob = 0.5;
public:
    BitFlipProb(double prob);
    Individual *mutate(Individual *input, int k);
};
