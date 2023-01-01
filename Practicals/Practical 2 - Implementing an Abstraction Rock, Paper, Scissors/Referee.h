#pragma once
#include "Human.h"
#include "Computer.h"

class Referee{
    public:
        Referee();
        char refGame(HumanPlayer player1, ComputerPlayer player2);
};