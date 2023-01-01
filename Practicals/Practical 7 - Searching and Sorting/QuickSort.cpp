#include "QuickSort.h"

std::vector<int> QuickSort::sort(std::vector<int> list){
  if (list.size() < 2){
    return list;
  } else if (list.size() == 2){
    if (list.at(0) > list.at(1)){
      int temp = list.at(0);
      list.at(0) = list.at(1);
      list.at(1) = temp;
    }
    return list;
  } else{
    int pivot = list.at(2);
    std::vector<int> p1;
    std::vector<int> p2;
    for (unsigned int i = 0; i < list.size(); i++){
      if (i!=2){
        if (list.at(i) <=  pivot){
          p1.push_back(list.at(i));
        } else{
          p2.push_back(list.at(i));
        }
      }
    }
    std::vector<int> s1 = sort(p1); // recursion woo
    std::vector<int> s2 = sort(p2);
    std::vector<int> r;
    for (unsigned int i = 0; i < s1.size(); i++){
      r.push_back(s1.at(i));
    }
    r.push_back(pivot);
    for (unsigned int i = 0; i < s2.size(); i++){
      r.push_back(s2.at(i));
    }
    return r; // return vector after combining everything back
  }
}
