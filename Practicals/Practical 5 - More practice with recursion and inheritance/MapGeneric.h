#pragma once
#include <vector>

class MapGeneric{
public:
    std::vector<int> map(std::vector<int> inputvec);
private:
    virtual int f(int i)=0;
protected:
    std::vector<int> output;
};
