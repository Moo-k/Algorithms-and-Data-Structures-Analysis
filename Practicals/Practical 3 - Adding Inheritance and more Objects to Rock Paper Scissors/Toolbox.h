#pragma once
#include <string>
#include "Computer.h"

class Toolbox: public Computer{
    public:
        Toolbox();
        char makeMove();
        std::string getName();
        void resetMoveCount();
    private:
        std::string name;
        int moveCount;
};