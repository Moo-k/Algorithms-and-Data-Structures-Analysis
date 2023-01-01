#pragma once
#include <vector>
#include "FilterGeneric.h"

class FilterOdd: public FilterGeneric{
public:
    std::vector<int> filter(std::vector<int> inputvec);
private:
    bool g(int i);
};
