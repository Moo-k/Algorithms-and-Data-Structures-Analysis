#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list){
  int size = list.size();
  for (int i = size-1; i >= 0; i--){
    for (int j = 0; j <= i; j++ ){
      if (j==size-1){
        break;
      } else if (list.at(j) > list.at(j+1)){
        int temp = list.at(j);
        list.at(j) = list.at(j+1);
        list.at(j+1) = temp;
      }
    }
  }
  return list;
}
