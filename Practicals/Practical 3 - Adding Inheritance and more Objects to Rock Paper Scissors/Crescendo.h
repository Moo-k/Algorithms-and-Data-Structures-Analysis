#pragma once
#include <string>
#include "Computer.h"

class Crescendo: public Computer{
    public:
        Crescendo();
        char makeMove();
        std::string getName();
        void resetMoveCount();
    private:
        std::string name;
        int moveCount;
};