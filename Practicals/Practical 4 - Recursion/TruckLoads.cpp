#include "TruckLoads.h"
#include <iostream>

int Truckloads::numTrucks(int numCrates, int loadSize){
  if (numCrates < 0 || loadSize < 0){
    std::cerr << "ERROR";
    exit(1);
  } else if (numCrates == 0){
    return 0;
  } else if (loadSize >= numCrates){
    return 1;
  } else{
    return numTrucks(numCrates/2,loadSize)+numTrucks(numCrates-numCrates/2,loadSize); // way to get half + the other half (regardless of odd or even)
  }
}
