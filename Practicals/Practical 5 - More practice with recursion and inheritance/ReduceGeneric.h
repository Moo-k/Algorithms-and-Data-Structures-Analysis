#pragma once
#include <vector>

class ReduceGeneric{
public:
    int reduce(std::vector<int> inputvec);
private:
    virtual int binaryOperator(int x, int y)=0;
};
