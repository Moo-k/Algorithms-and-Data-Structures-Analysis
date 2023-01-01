#include "Human.h"
#include <iostream>

HumanPlayer::HumanPlayer(){

};

char HumanPlayer::makeMove(){
    char move = '\0';
    std::cout << "Enter move: ";
    std::cin >> move;
    return move;
}