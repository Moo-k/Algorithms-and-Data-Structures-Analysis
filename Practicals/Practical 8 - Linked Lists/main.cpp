#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main(void){
  string array[103];
  string input; // read input as string and split into strings
  getline(cin,input);
  stringstream in(input);
  string temp;
  int pos = 0;
  while(in >> temp){
    array[pos] = temp;
    pos++;
  }
  int intarray[100];
  for (int i = 0; i < pos-3; i++){
    intarray[i] = stoi(array[i]);
  }
  string cmd = array[pos-3];
  int param1 = stoi(array[pos-2]);
  int param2 = stoi(array[pos-1]);
  LinkedList *ll = new LinkedList(intarray,pos-3);

  switch (cmd[0]){
    case 'S':
      ll->search(param1);
      break;
    case 'G':
      ll->getItem(param1);
      break;
    case 'A':
      switch (cmd[1]){
        case 'F':
          ll->addFront(param1);
          break;
        case 'E':
          ll->addEnd(param1);
          break;
        case 'P':
          ll->addAtPosition(param1,param2);
          break;
      }
      break;
    case 'D':
      switch (cmd[1]){
        case 'F':
          ll->deleteFront();
          break;
        case 'E':
          ll->deleteEnd();
          break;
        case 'P':
          ll->deletePosition(param1);
          break;
      }
      break;
  }
  ll->printItems();
  return 0;
}
