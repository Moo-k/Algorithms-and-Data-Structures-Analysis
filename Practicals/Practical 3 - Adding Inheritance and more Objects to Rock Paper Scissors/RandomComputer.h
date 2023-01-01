#pragma once
#include <string>
#include "Computer.h"

class RandomComputer: public Computer{
    public:
        RandomComputer();
        char makeMove();
        std::string getName();
        void resetMoveCount();
    private:
        std::string name;
        int moveCount;
};