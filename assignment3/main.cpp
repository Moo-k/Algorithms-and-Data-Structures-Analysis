#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

static string table[26] = {""}; // static table of 26 possible inputs

int findString(string tofind){
  for (int i = 0; i < 26; i++){
    if (table[i] == tofind){
      return i;
    }
  }
  return -1;
}

int main(void){
  string input; // string to read in input as a single string
  getline(cin,input);
  stringstream ss(input); // read input as a stream

  while (ss.good()){
    string temp; // token of current input
    ss >> temp;
    if (temp.front() == 'A'){ // add
      int index = findString(temp.substr(1));
      if (index == -1){
        index = temp.back()-'a';
        while (!table[index].empty()){
          index++;
          if (index >= 26){
            index-=26;
          }
        }
        table[index] = temp.substr(1);
      }
    } else if (temp.front() == 'D'){ // delete
      int index = findString(temp.substr(1));
      if (index >= 0){
        table[index] = ""; // misunderstood question: in case of deletion, space is freed up, not deprecated
      }
    }
  }

  for (int i = 0; i < 26; i++){
    if (!(table[i].empty()) && table[i]!="-"){ // if the slot is not empty and not a tombstone, print
      cout << table[i] << " ";
    }
  }

  return 0;
}
