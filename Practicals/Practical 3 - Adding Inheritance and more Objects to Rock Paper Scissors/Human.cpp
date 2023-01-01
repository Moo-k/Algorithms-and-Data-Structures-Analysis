#include "Human.h"
#include <iostream>

Human::Human(){
    name="placeholder";
}

Human::Human(std::string nameInput){
    name = nameInput;
}

char Human::makeMove(){
    move = '\0';
    while (move!='R' && move!='P' && move!='S'){
        std::cout << "Enter move: ";
        std::cin >> move;
    }
    return move;
}

std::string Human::getName(){
    return name;
}