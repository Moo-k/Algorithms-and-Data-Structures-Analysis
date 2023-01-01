#include "FilterOdd.h"

std::vector<int> FilterOdd::filter(std::vector<int> inputvec){
  if (inputvec.empty()){
    return output;
  } else{
    if (g(inputvec.back())){
      output.insert(output.begin(),inputvec.back());
    }
    inputvec.pop_back();
    return filter(inputvec);
  }
}

bool FilterOdd::g(int i){
  if(i%2==0){
    return false;
  } else{
    return true;
  }
}
