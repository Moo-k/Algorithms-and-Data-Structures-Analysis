#pragma once
#include <array>
#include "Referee.h"

class Tournament{
public:
    Tournament();
    Player *run(std::array<Player *, 8> competitors);
};