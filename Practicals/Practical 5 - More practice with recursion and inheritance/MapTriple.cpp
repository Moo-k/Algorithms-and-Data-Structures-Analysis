#include "MapTriple.h"

std::vector<int> MapTriple::map(std::vector<int> inputvec){
  if (inputvec.empty()){
    return output;
  } else{
    output.insert(output.begin(),f(inputvec.back()));
    inputvec.pop_back();
    return map(inputvec);
  }
}

int MapTriple::f(int i){
  return 3*i;
}
