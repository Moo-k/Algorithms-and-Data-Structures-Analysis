#pragma once
#include <vector>
#include "FilterGeneric.h"

class FilterNonPositive: public FilterGeneric{
public:
    std::vector<int> filter(std::vector<int> inputvec);
private:
    bool g(int i);
};
