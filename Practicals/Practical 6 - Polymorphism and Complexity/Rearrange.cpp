#include "Rearrange.h"
#include <iostream>

Individual *Rearrange::mutate(Individual *input, int k){
  int pos = k%(input->getLength());
  if (pos==0){
    pos = input->getLength();
  }
  std::string rearranged = "";
  int loop = input->getLength();
  for (int i = pos; i < loop+1; i++){
    if (input->getBit(i)==1){
      rearranged.push_back('1');
    } else{
      rearranged.push_back('0');
    }
  }
  for (int i = 1; i < pos; i++){
    if (input->getBit(i)==1){
      rearranged.push_back('1');
    } else{
      rearranged.push_back('0');
    }
  }
  //std::cout << rearranged << std::endl;
  return new Individual(rearranged);
}
