#pragma once
#include <string>
#include <vector>

class Reverse{
    public:
    int reverseDigit(int value);
    std::string reverseString(std::string letters);
    private:
    static int icounter;
    static unsigned int scounter;
    static int irev;
    static std::string srev;
};
