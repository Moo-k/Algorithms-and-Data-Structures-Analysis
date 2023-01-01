#include "Avalanche.h"

Avalanche::Avalanche(){
    name = "Avalanche";
    moveCount = 0;
}

char Avalanche::makeMove(){
    moveCount++;
    return 'R';
}

std::string Avalanche::getName(){
    return name;
}

void Avalanche::resetMoveCount(){
    moveCount = 0;
}