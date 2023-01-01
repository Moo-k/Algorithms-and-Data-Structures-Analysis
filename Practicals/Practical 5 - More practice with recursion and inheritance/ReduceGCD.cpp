#include "ReduceGCD.h"

int ReduceGCD::reduce(std::vector<int> inputvec){
  if (inputvec.size()==1){
    return gcd;
  } else{
    int temp = binaryOperator(inputvec.at(0),inputvec.at(1));
    inputvec.erase(inputvec.begin());
    if (temp < gcd){
      gcd = temp;
    }
    reduce(inputvec);
    return gcd;
  }
}

int ReduceGCD::binaryOperator(int x, int y){
  int gcd2 = 0;
  if (x < y){
    for (int i = x; i > 0; i--){
      if (x%i==0 && y%i==0){
        gcd2 = i;
        break;
      }
    }
  } else{
    for (int i = y; i > 0; i--){
      if (x%i==0 && y%i==0){
        gcd2 = i;
        break;
      }
    }
  }
  return gcd2;
}
