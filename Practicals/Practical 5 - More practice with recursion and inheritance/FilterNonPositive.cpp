#include "FilterNonPositive.h"

std::vector<int> FilterNonPositive::filter(std::vector<int> inputvec){
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

bool FilterNonPositive::g(int i){
  if (i < 0){
    return true;
  } else{
    return false;
  }
}
