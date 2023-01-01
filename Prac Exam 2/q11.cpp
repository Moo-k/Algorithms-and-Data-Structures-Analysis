#include <iostream>

using namespace std;

int sumOfSquare2(int n, int sum){ // making sure that total sum is passed on with each iteration, thus tail recursion
  if (n < 0){ // error case (base case is 1^2)
    return 0;
  } else if (n == 1){
    return sum+1; // base case
  } else {
    return sumOfSquare2(n-1,sum+(n*n)); // n^2 + sum of lower square
  }
}

int sumOfSquare(int n){ // tail recursion
  return sumOfSquare2(n,0); // using a helper function
}

int main(void){
  cout << sumOfSquare(-1) << endl; // test cases
  cout << sumOfSquare(0) << endl;
  cout << sumOfSquare(3) << endl;
  cout << sumOfSquare(4) << endl;
  return 0;
}
