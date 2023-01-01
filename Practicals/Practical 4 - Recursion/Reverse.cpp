#include "Reverse.h"
#include <string>
#include <cmath>
#include <iostream>

int Reverse::icounter = 1;
unsigned int Reverse::scounter = 0;
int Reverse::irev = 0;
std::string Reverse::srev = "";

int Reverse::reverseDigit(int value){
  if (value < 0){
    std::cout << "ERROR";
    exit(1);
  } else if (value > 0){
    reverseDigit(value/10);
    irev += (value%10)*icounter;
    icounter *= 10;
  } else {
    icounter = 1;
    irev = 0;
  }
  return irev;
}

std::string Reverse::reverseString(std::string letters){
  if (scounter < letters.length()){
    reverseString(letters.substr(0,letters.length()-1));
    srev = letters.back()+srev;
    scounter++;
  } else { // doesnt reset properly
    scounter = 0;
    srev = "";
  }
  return srev;
}
