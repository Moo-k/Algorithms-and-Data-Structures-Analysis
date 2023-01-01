#pragma once
#include <vector>

class FilterGeneric{
public:
    std::vector<int> filter(std::vector<int> inputvec);
private:
    virtual bool g(int i)=0;
protected:
    std::vector<int> output;
};
