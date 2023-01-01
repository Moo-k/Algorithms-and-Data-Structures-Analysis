#pragma once
#include <string>
#include "Computer.h"

class Bureaucrat: public Computer{
    public:
        Bureaucrat();
        char makeMove();
        std::string getName();
        void resetMoveCount();
    private:
        std::string name;
        int moveCount;
};