#include "MapAbsoluteValue.h"
#include <cmath>

std::vector<int> MapAbsoluteValue::map(std::vector<int> inputvec){
  if (inputvec.empty()){
    return output;
  } else{
    output.insert(output.begin(),f(inputvec.back()));
    inputvec.pop_back();
    return map(inputvec);
  }
}

int MapAbsoluteValue::f(int i){
  return abs(i);
}
