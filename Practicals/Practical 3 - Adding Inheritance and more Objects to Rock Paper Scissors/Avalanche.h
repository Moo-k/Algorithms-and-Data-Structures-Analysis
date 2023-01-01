#pragma once
#include <string>
#include "Computer.h"

class Avalanche: public Computer{
    public:
        Avalanche();
        char makeMove();
        std::string getName();
        void resetMoveCount();
    private:
        std::string name;
        int moveCount;
};