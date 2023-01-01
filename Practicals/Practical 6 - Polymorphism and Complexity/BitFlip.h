#pragma once
#include "Mutator.h"

class BitFlip: public Mutator{
public:
    Individual *mutate(Individual *input, int k);
};
