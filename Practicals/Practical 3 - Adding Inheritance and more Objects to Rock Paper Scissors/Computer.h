#pragma once
#include <string>
#include "Player.h"

class Computer: public Player{
    public:
        Computer();
        char makeMove()=0;
        std::string getName();
        void resetMoveCount();
};