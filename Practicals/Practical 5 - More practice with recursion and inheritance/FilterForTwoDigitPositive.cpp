#include "FilterForTwoDigitPositive.h"

std::vector<int> FilterForTwoDigitPositive::filter(std::vector<int> inputvec){
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

bool FilterForTwoDigitPositive::g(int i){
  if (i < 100 && i > 9){
    return true;
  } else{
    return false;
  }
}
