#include "PaperDoll.h"

PaperDoll::PaperDoll(){
    name = "PaperDoll";
    moveCount = 0;
}

char PaperDoll::makeMove(){
    moveCount++;
    int counter = moveCount%3;
    switch (counter){
        case 0:
            return 'S';
        case 1:
            return 'P';
        case 2:
            return 'S';
        default:
            return 'E';
    }
}

std::string PaperDoll::getName(){
    return name;
}

void PaperDoll::resetMoveCount(){
    moveCount = 0;
}