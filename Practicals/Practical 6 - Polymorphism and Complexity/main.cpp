#include "Individual.h"
#include "Mutator.h"
#include "BitFlip.h"
#include "BitFlipProb.h"
#include "Rearrange.h"
#include <iostream>
#include <string>

using namespace std;

Individual *execute(Individual *indPtr, Mutator *mPtr, int k){
  return mPtr->mutate(indPtr,k);
}


int main(void){
  string binarystr1;
  string binarystr2;
  int k1;
  int k2;
  //cout << "Enter input: ";
  cin >> binarystr1 >> k1 >> binarystr2 >> k2;

  Individual *i1 = new Individual(binarystr1);
  Individual *i2 = new Individual(binarystr2);
  BitFlip *bf = new BitFlip();
  Rearrange *re = new Rearrange();

  i1 = execute(i1,bf,k1);
  i2 = execute(i2,re,k2);
  cout << i1->getString() << " " << i2->getString() << " " << i2->getMaxOnes() << endl;

  return 0;
}
