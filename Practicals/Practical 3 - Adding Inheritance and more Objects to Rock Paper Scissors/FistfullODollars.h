#pragma once
#include <string>
#include "Computer.h"

class FistfullODollars: public Computer{
    public:
        FistfullODollars();
        char makeMove();
        std::string getName();
        void resetMoveCount();
    private:
        std::string name;
        int moveCount;
};