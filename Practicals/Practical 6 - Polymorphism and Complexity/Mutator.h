#pragma once
#include "Individual.h"

class Mutator: public Individual{
public:
    Mutator();
    virtual Individual *mutate(Individual *input, int k)=0;
};
