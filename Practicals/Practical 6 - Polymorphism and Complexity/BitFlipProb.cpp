#include "BitFlipProb.h"
#include <random>

BitFlipProb::BitFlipProb(double prob){
  this->prob = prob;
}

Individual *BitFlipProb::mutate(Individual *input, int k){
  std::uniform_real_distribution<double> unif(0,1);
  std::default_random_engine re;
  double randomDouble = 0;
  int loop = input->getLength();
  for (int i = 0; i < loop;i++){
    randomDouble = unif(re);
    if (randomDouble < prob){
       input->flipBit(i+1);
    }
  }
  return input;
}
