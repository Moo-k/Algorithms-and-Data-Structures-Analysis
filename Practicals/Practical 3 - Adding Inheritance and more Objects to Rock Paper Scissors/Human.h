#pragma once
#include <string>
#include "Player.h"

class Human: public Player{
    public:
        Human();
        Human(std::string nameInput);
        char makeMove();
        std::string getName();
    private:
        std::string name;
        char move;
};