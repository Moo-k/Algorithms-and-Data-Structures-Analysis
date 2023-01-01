#include "MapGeneric.h"
#include "MapTriple.h"
#include "MapSquare.h"
#include "MapAbsoluteValue.h"
#include "FilterGeneric.h"
#include "FilterOdd.h"
#include "FilterNonPositive.h"
#include "FilterForTwoDigitPositive.h"
#include "ReduceGeneric.h"
#include "ReduceMinimum.h"
#include "ReduceGCD.h"
#include <iostream>
#include <vector>
using namespace std;

int main(void){
  vector<int> L;
  for (int i = 0; i < 20; i++){
    if (i < 19){
      int temp;
      char temp2;
      cin >> temp >> temp2;
      L.push_back(temp);
    } else{
      int temp;
      cin >> temp;
      L.push_back(temp);
    }
  }
  MapAbsoluteValue *mapabs = new MapAbsoluteValue();
  MapTriple *maptrip = new MapTriple();
  vector<int> Lprime = maptrip->map(mapabs->map(L));
  /*for (int i = 0; i < Lprime.size(); i++){
    cout << Lprime.at(i) << " ";
  }
  cout << endl;*/

  FilterForTwoDigitPositive *fftdp = new FilterForTwoDigitPositive();
  FilterOdd *fodd = new FilterOdd();
  vector<int> Lprime2 = fodd->filter(fftdp->filter(Lprime));
  /*for (int i = 0; i < Lprime2.size(); i++){
    cout << Lprime2.at(i) << " ";
  }
  cout << endl;*/

  ReduceMinimum *min = new ReduceMinimum();
  ReduceGCD *gcd = new ReduceGCD();
  cout << min->reduce(Lprime2) << " " << gcd->reduce(Lprime2) << endl;

  return 0;
}
