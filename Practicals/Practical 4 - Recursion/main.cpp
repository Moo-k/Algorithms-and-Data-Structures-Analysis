#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "Reverse.h"
#include "TruckLoads.h"
#include "EfficientTruckLoads.h"

using namespace std;

int main(void){
  int i = 0;
  string s = "";
  unsigned int numCrates = 0;
  unsigned int loadSize = 0;
  Reverse *r= new Reverse();
  Truckloads *t = new Truckloads();
  EfficientTruckloads *e = new EfficientTruckloads();

  cout << "Enter input: ";
  cin >> i >> s >> numCrates >> loadSize;

  int irev = 0;
  if (i>=0){
    irev = r->reverseDigit(i);
    cout << irev << " ";
  } else{
    cerr <<"ERROR ";
  }
  string srev = "";
  if (s.empty()==false){
    srev = r->reverseString(s);
    cout << srev << " ";
  } else{
    cerr <<"ERROR ";
  }
  int tl = 0;
  if (numCrates >= 0 && loadSize > 0){
    tl = t->numTrucks(numCrates,loadSize);
    cout << tl << " ";
  } else{
    cerr <<"ERROR ";
  }
  int el = 0;
  if (numCrates >= 0 && loadSize > 0){
    el = e->numTrucks(numCrates,loadSize);
    cout << el;
  } else{
    cerr <<"ERROR ";
  }

  //cout << r->reverseDigit(i) << " " << r->reverseString(s) << " " << t->numTrucks(numCrates,loadSize) << " " << e->numTrucks(numCrates,loadSize) << endl;

  return 0;
}
