#include "Individual.h"
#include <iostream>

Individual::Individual(){

};

Individual::Individual(int length){
  binaryString = "";
  for (int i = 0; i < length; i++){
    binaryString.push_back('1');
  }
}

Individual::Individual(std::string binaryString){
  this->binaryString = binaryString;
}

std::string Individual::getString(){
  return binaryString;
}

int Individual::getBit(int pos){
  unsigned int temp = pos;
  if (temp>binaryString.size()){
    return -1;
  } else if (binaryString.at(temp-1)=='1'){
    return 1;
  } else{
    return 0;
  }
}

void Individual::flipBit(int pos){
  unsigned int temp = pos;
  if (temp>binaryString.size()){
    std::cerr << "Error" << std::endl;
  } else if (binaryString.at(temp-1)=='1'){
    binaryString.at(temp-1)='0';
  } else{
    binaryString.at(temp-1)='1';
  }
}

int Individual::getMaxOnes(){
  int maxOnes = 0;
  int tempOnes = 0;
  for (unsigned int i = 0; i < binaryString.size(); i++){
    if (binaryString.at(i)=='0'){
      if (tempOnes>maxOnes){
        maxOnes=tempOnes;
      }
      tempOnes = 0;
    } else{
      tempOnes++;
    }
  }
  if (tempOnes>maxOnes){
      maxOnes=tempOnes;
  }
  return maxOnes;
}

int Individual::getLength(){
  return binaryString.size();
}
