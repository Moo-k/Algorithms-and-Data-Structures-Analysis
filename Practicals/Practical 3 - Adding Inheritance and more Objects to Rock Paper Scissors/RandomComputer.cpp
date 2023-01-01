#include "RandomComputer.h"
#include <random>

RandomComputer::RandomComputer(){
    name = "RandomComputer";
    moveCount = 0;
}

char RandomComputer::makeMove(){
    moveCount++;
    std::random_device rd;
    std::uniform_int_distribution<unsigned> choices(0,2);
    int rng = choices(rd);
    switch (rng){
        case 0:
            return 'R';
        case 1:
            return 'P';
        case 2:
            return 'S';
        default:
            return 'E';
    }
}

std::string RandomComputer::getName(){
    return name;
}

void RandomComputer::resetMoveCount(){
    moveCount = 0;
}