#include <iostream>

using namespace std;

int sumOfSquare(int n){ // head recursion
  if (n <= 0){ // error case (base case is 1^2)
    return 0;
  } else if (n == 1){
    return 1; // 1^2 = 1
  } else{
    return sumOfSquare(n-1)+n*n; // n^2 + sum of lower square
  }
}

int main(void){
  cout << sumOfSquare(-1) << endl; // test cases
  cout << sumOfSquare(0) << endl;
  cout << sumOfSquare(3) << endl;
  cout << sumOfSquare(4) << endl;
  return 0;
}
