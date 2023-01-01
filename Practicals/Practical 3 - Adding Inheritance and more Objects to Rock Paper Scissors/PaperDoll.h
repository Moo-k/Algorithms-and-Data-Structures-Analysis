#pragma once
#include <string>
#include "Computer.h"

class PaperDoll: public Computer{
    public:
        PaperDoll();
        char makeMove();
        std::string getName();
        void resetMoveCount();
    private:
        std::string name;
        int moveCount;
};