#include "MapSquare.h"

std::vector<int> MapSquare::map(std::vector<int> inputvec){
  if (inputvec.empty()){
    return output;
  } else{
    output.insert(output.begin(),f(inputvec.back()));
    inputvec.pop_back();
    return map(inputvec);
  }
}

int MapSquare::f(int i){
  return i*i;
}
