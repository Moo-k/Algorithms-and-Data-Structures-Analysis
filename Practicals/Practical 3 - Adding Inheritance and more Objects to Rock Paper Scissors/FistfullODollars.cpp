#include "FistfullODollars.h"

FistfullODollars::FistfullODollars(){
    name = "FistfullODollars";
    moveCount = 0;
}

char FistfullODollars::makeMove(){

    int counter = moveCount%3;
    switch (counter){
        case 0:
            moveCount++;
            return 'R';
        case 1:
            moveCount++;
            return 'P';
        case 2:
            moveCount++;
            return 'P';
        default:
            return 'E';
    }
}

std::string FistfullODollars::getName(){
    return name;
}

void FistfullODollars::resetMoveCount(){
    moveCount = 0;
}