#pragma once
#include "Mutator.h"

class Rearrange: public Mutator{
public:
    Individual *mutate(Individual *input, int k);
};
