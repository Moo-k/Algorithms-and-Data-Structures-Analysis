#pragma once
#include <string>

class Player{
    public:
        Player();
        virtual char makeMove()=0;
        virtual std::string getName()=0;
        virtual void resetMoveCount()=0;
};