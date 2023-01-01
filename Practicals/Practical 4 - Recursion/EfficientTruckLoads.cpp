#include "EfficientTruckLoads.h"
#include <iostream>
#include <vector>

int EfficientTruckloads::numTrucks(int numCrates, int loadSize){
  //std::cout << "numTrucks" << numCrates << ", " << loadSize << std::endl;
  if (numCrates == 0){
    return 0;
  }
  static std::vector<int> values;
  if (values.empty()){
    for (int i = 0; i < numCrates; i++){
      values.push_back(-1);
    }
  }
  if (numCrates < 0 || loadSize < 0){ // erroneos input
    std::cout << "ERROR";
    exit(1);
  } else if (loadSize >= numCrates){ // base case
    values.at(numCrates-1) = 1;
    return 1;
  } else{
    int val = values.at(numCrates-1);
    if (val == -1){
      val = numTrucks(numCrates/2,loadSize)+numTrucks(numCrates-numCrates/2,loadSize);
      values.at(numCrates-1) = val;
      //std::cout << "storing numCrates val" << numCrates-1 << std::endl;
    } /*else{
      std::cout << "found" << numCrates-1 << std::endl;
    }*/
    return values.at(numCrates-1);
    //return numTrucks(numCrates/2,loadSize)+numTrucks(numCrates-numCrates/2,loadSize); // way to get half + the other half (regardless of odd or even)
  }
}
