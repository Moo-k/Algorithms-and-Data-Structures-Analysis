#pragma once
#include <vector>
#include <climits>
#include "ReduceGeneric.h"

class ReduceGCD: public ReduceGeneric{
public:
    int reduce(std::vector<int> inputvec);
private:
    int binaryOperator(int x, int y);
    int gcd = INT_MAX;
};
