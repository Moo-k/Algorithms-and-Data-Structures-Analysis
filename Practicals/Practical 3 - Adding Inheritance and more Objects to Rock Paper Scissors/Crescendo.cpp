#include "Crescendo.h"

Crescendo::Crescendo(){
    name = "Crescendo";
    moveCount = 0;
}

char Crescendo::makeMove(){
    moveCount++;
    switch (moveCount%3){
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

std::string Crescendo::getName(){
    return name;
}

void Crescendo::resetMoveCount(){
    moveCount = 0;
}