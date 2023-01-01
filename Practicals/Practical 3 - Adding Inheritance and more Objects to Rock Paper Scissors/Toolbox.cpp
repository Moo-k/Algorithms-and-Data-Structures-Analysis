#include "Toolbox.h"

Toolbox::Toolbox(){
    name = "Toolbox";
    moveCount = 0;
}

char Toolbox::makeMove(){
    moveCount++;
    return 'S';
}

std::string Toolbox::getName(){
    return name;
}

void Toolbox::resetMoveCount(){
    moveCount = 0;
}