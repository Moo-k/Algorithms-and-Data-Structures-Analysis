#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string schadd(string i1, string i2, int base, int carry, string out){
  if (i1.empty()&&i2.empty()&&carry==0){ // base case
    return out;
  }
  char l1 = '\0';
  char l2 = '\0';
  if (i1.empty()){
    l1 = '0';
  } else{
    l1 = i1.back(); // last digit of i1
    i1.pop_back();
  }
  if (i2.empty()){
    l2 = '0';
  } else{
    l2 = i2.back(); // last digit of i2
    i2.pop_back();
  }
  int sum = l1-'0'+l2-'0'+carry;
  if (sum >= base){
    carry = 1;
    sum-=base;
  } else{
    carry = 0;
  }
  string temp = to_string(sum);
  out.insert(0,temp);
  return schadd(i1,i2,base,carry,out);
}

string schminus(string i1, string i2, int base, string out){
  if (i1.empty()&&i2.empty()){
    return out;
  }
  char l1 = '\0';
  char l2 = '\0';
  if (i1.empty()){
    l1 = '0';
  } else{
    l1 = i1.back();
    i1.pop_back();
  }
  if (i2.empty()){
    l2 = '0';
  } else{
    l2 = i2.back();
    i2.pop_back();
  }
  int temp = (l1-'0')-(l2-'0');
  if (temp < 0){
    temp+=base;
    int index = i1.size()-1;
    char max = (char)(base-1+'0');
    while (i1.at(index)=='0'){
      i1.at(index) = max;
      index--;
      if (index < 0){
        cerr << "!";
        exit(1);
      }
    }
    i1.at(index) = i1.at(index)-1;
  }
  string temp2 = to_string(temp);
  out.insert(0,temp2);
  return schminus(i1,i2,base,out);
}

string karatsuba(string i1, string i2, int base){
  if (i1.size() <= 2 && i2.size() <= 2){
    string pad = "0";
    while (i1.size() < 2){
      i1.insert(0,pad);
    }
    while (i2.size() < 2){
      i2.insert(0,pad);
    }
    int i11 = i1.front()-'0';
    int i12 = i1.back()-'0';
    int i21 = i2.front()-'0';
    int i22 = i2.back()-'0';
    string first = "0";
    for (int i = 0; i < i21; i++){
      first = schadd(first,to_string(i11),base,0,"");
    }
    // cout << "first: " << first << endl;
    string second = "0";
    for (int i = 0; i < i22; i++){
      second = schadd(second,to_string(i12),base,0,"");
    }
    // cout << "second: " << second << endl;
    string third1 = schadd(to_string(i11),to_string(i12),base,0,"");
    // cout << "third1: " << third1 << endl;
    string third2 = schadd(to_string(i21),to_string(i22),base,0,"");
    // cout << "third2: " << third2 << endl;
    int third2int = stoi(third2,nullptr,base);
    string third = "0";
    for (int i = 0; i < third2int; i++){
      third = schadd(third,third1,base,0,"");
    }
    // cout << "third: " << third << endl;
    string firstandsecond = schadd(first,second,base,0,"");
    // cout << "firstandsecond: " << firstandsecond << endl;
    string fourth = schminus(third,firstandsecond,base,"");
    // cout << "fourth: " << fourth << endl;
    string first2 = first + "00";
    string ans1 = schadd(first2,second,base,0,"");
    // cout << "ans1: " << ans1 << endl;
    string fourth2 = fourth + "0";
    string ans2 = schadd(ans1,fourth2,base,0,"");
    while (ans2.front()=='0'){
      ans2.erase(ans2.begin());
    }
    return ans2;
  } else{
    unsigned int maxindex = max(i1.size(),i2.size())-1;
    if (maxindex%2==0){ maxindex+=1; }
    while (i1.size()<maxindex+1 || i2.size()<maxindex+1){
      if (i1.size()<maxindex+1){
        i1.insert(0,"0");
      }
      if (i2.size()<maxindex+1){
        i2.insert(0,"0");
      }
    }
    
    int half = (maxindex+1)/2;
    string i11 = i1.substr(0,half);
    string i12 = i1.substr(half);
    string i21 = i2.substr(0,half);
    string i22 = i2.substr(half);
    // cout << "i11: " << i11 << endl;
    // cout << "i12: " << i12 << endl;
    // cout << "i21: " << i21 << endl;
    // cout << "i22: " << i22 << endl;
    string first = karatsuba(i11,i21,base);
    string temp = first;
    for (int i = 0; i < 2*half; i++){
      first.push_back('0');
    }
    // cout << "first: " << first << endl;
    string second = karatsuba(i12,i22,base);
    // cout << "second: " << second << endl;
    string tempandsecond = schadd(temp,second,base,0,"");
    // cout << "temp + second: " << tempandsecond << endl;
    string third1 = schadd(i11,i12,base,0,"");
    string third2 = schadd(i21,i22,base,0,"");
    // cout << "third1: " << third1 << endl;
    // cout << "third2: " << third2 << endl;
    string third3 = karatsuba(third1,third2,base);
    // cout << "third3: " << third3 << endl;
    string third4 = schminus(third3,tempandsecond,base,"");
    // cout << "third4: " << third4 << endl;
    for (int i = 0; i < half; i++){
      third4.push_back('0');
    }
    // cout << "third4`: " << third4 << endl;
    string firstandsecond = schadd(first,second,base,0,"");
    // cout << "firstandsecond: " << firstandsecond << endl;
    string all = schadd(firstandsecond,third4,base,0,"");
    // cout << "all: " << all << endl;
    while (all.front()=='0'){
      all.erase(all.begin());
    }
    return all;
  }
}

int main(void){
  string i1;
  string i2;
  int b = 0;
  cin >> i1 >> i2 >> b;
  cout << schadd(i1,i2,b,0,"") << " " << karatsuba(i1,i2,b) << " 0" << endl;

  return 0;
}
