#pragma once
#include <vector>
#include <climits>
#include "ReduceGeneric.h"

class ReduceMinimum: public ReduceGeneric{
public:
    int reduce(std::vector<int> inputvec);
private:
    int binaryOperator(int x, int y);
    int minimum = INT_MAX;
};
