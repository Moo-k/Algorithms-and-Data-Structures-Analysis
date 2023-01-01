#include "ReduceMinimum.h"

int ReduceMinimum::reduce(std::vector<int> inputvec){
  if (inputvec.size()==0){
    return minimum;
  } else{
    minimum = binaryOperator(minimum,inputvec.back());
    inputvec.pop_back();
    reduce(inputvec);
    return minimum;
  }
}

int ReduceMinimum::binaryOperator(int x, int y){
  if (x < y){
    return x;
  } else{
    return y;
  }
}
