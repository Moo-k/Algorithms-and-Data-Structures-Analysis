#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Sort.h"
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
using namespace std;

int main(void){
  vector<int> list;

  string intlist; // read input as string and split into ints using space delimiter
  getline(cin,intlist);
  stringstream in(intlist);
  int temp;
  while(in >> temp){
    list.push_back(temp);
  }
  
  QuickSort *qs = new QuickSort();
  RecursiveBinarySearch *rbs = new RecursiveBinarySearch();
  vector<int>list2 = qs->sort(list);
  if (rbs->search(list2,1)){
    cout << "true ";
  } else{
    cout << "false ";
  }
  for (int i = 0; i < list2.size(); i++){
    cout << list2.at(i) << " ";
  }
  cout << endl;
  return 0;
}
