#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int target){
  if (list.size() == 1){
    if (list.at(0) == target){
      return true;
    } else{
      return false;
    }
  }
  if (list.size() == 2){
    if ((list.at(0) == target) | (list.at(1) == target)){
      return true;
    } else{
      return false;
    }
  }
  int mid = list.size()/2; // rounds down
  if (list.at(mid) == target){
    return true;
  } else if (list.at(mid) < target){
    std::vector<int> list2;
    for (unsigned int i = mid+1; i < list.size(); i++){
      list2.push_back(list.at(i));
    }
    return search(list2,target);
  } else if (list.at(mid) > target){
    std::vector<int> list2; // shorten list to relevant part O(n)
    for (int i = 0; i < mid; i++){
      list2.push_back(list.at(i));
    }
    return search(list2,target);
  } else{
    return false;
  }
}
