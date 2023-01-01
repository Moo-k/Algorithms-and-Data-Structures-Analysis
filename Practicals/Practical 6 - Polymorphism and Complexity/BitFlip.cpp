#include "BitFlip.h"

Individual *BitFlip::mutate(Individual *input, int k){
  int pos = k%(input->getLength());
  if (pos==0){
    pos = input->getLength();
  }
  input->flipBit(pos);
  return input;
}
