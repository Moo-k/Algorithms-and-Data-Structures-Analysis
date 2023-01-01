#pragma once
#include <string>

class Individual{
private:
    std::string binaryString;
public:
    Individual();
    Individual(int length);
    Individual(std::string binaryString);
    std::string getString(); // The function outputs a binary string representation of the bitstring list (e.g.“01010100”).
    int getBit(int pos); // The function returns the bit value at position pos. It should return -1 if pos is out of bound..
    void flipBit(int pos); // The function takes in the position of the certain bit and flip the bit value.
    int getMaxOnes(); // The function returns the longest consecutive sequence of ‘1’ digits in the list (e.g. calling the function on “1001110” will obtain 3).
    int getLength();
};
