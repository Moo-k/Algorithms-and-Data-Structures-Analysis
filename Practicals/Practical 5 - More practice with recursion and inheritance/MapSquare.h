#pragma once
#include <vector>
#include "MapGeneric.h"

class MapSquare: public MapGeneric{
public:
    std::vector<int> map(std::vector<int> inputvec);
private:
    int f(int i);
};
