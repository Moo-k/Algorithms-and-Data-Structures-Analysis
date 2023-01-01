#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(){
    name = "Bureaucrat";
    moveCount = 0;
}

char Bureaucrat::makeMove(){
    moveCount++;
    return 'P';
}

std::string Bureaucrat::getName(){
    return name;
}

void Bureaucrat::resetMoveCount(){
    moveCount = 0;
}