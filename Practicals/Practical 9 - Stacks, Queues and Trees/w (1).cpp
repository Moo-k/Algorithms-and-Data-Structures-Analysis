// discussed with friend, own code missed hidden case 5 and i cant find any differences in output so i followed his format
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    vector<string> strvec;
    string input; // read input as string and split into strings
    getline(cin,input);
    stringstream in(input);
    string temp;
    int size = 0;
    while(in >> temp){
      strvec.push_back(temp);
      size++;
    }
    int ops = 0;
    //get number of operators
    for (int i=0;i<size;i++)
    {
        if (strvec[i] == "+" || strvec[i] == "-" || strvec[i] == "/" || strvec[i] == "*")
        {
            ops++;
        }
    }
    int ans = 0;
    string infix;

    if (size != 2*ops+1)
    {
        cout << "Error";
    } else if (size==1 && ops==0) {
        cout << strvec[0] + " = " + strvec[0] << endl;
    } else {
        int P = ops;
        int steps = 1;

        int num1 = stoi(strvec[P]);
        int num2 = stoi(strvec[P+steps]);
        infix = strvec[P] + " " + strvec[P-steps] + " " + strvec[P+steps];
        if (strvec[P-steps] == "+") {
            ans = num1 + num2;
        } else if (strvec[P-steps] == "-") {
            ans = num1 - num2;
        } else if (strvec[P-steps] == "/") {
            ans = num1 / num2;
        } else if (strvec[P-steps] == "*") {
            ans = num1 * num2;
        }
        while (steps!=ops)
        {
            steps++;
            num1 = stoi(strvec[P+steps]);
            if (strvec[P-steps] == "+") {
                infix = infix + " + " + strvec[P+steps];
                ans += num1;
            } else if (strvec[P-steps] == "-") {
                infix = infix + " - " + strvec[P+steps];
                ans -= num1;
            } else if (strvec[P-steps] == "/") {
                infix = "(" + infix + ")" " / " + strvec[P+steps];
                ans /= num1;
            } else if (strvec[P-steps] == "*") {
                infix = "(" + infix + ")" " * " + strvec[P+steps];
                ans *= num1;
            }
        }
        cout << infix << " = " << ans << endl;
    }
    return 0;
}
/*
#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

void error(){
	cout << "Error";
}

int main(void){
	vector<string> strvec;
	string input; // read input as string and split into strings
	getline(cin,input);
	stringstream in(input);
	string temp;
	int size = 0;
	while(in >> temp){
    strvec.push_back(temp);
    size++;
  }
  vector<char> ops;
  char frontchar[(strvec.front()).size()+1];
  strcpy(frontchar, (strvec.front()).c_str());
  while((frontchar[0]=='+')|(frontchar[0]=='-')|(frontchar[0]=='*')|(frontchar[0]=='/')&&(frontchar[1]=='\0')){
    ops.insert(ops.begin(),frontchar[0]);
    strvec.erase(strvec.begin());
    strcpy(frontchar,(strvec.front()).c_str());
  }
  if (ops.size()+1!=strvec.size()){
    error();
  } else if (ops.size() == 0){
    cout << strvec.at(0) << " = " << strvec.at(0) << endl;
  } else{
    string infix = strvec.at(0) + " " + ops.at(0) + " " + strvec.at(1);
    int ans = stoi(strvec.at(0));
    switch (ops.at(0)){
      case '+':
        ans += stoi(strvec.at(1));
        break;
      case '-':
        ans -= stoi(strvec.at(1));
        break;
      case '*':
        ans *= stoi(strvec.at(1));
        break;
      case '/':
        ans /= stoi(strvec.at(1));
        break;
    }
    for (unsigned int i = 1; i < ops.size(); i++){
      switch (ops.at(i)){
        case '+':
          infix += " + " + strvec.at(i+1);
          ans += stoi(strvec.at(i+1));
          break;
        case '-':
          infix += " - " + strvec.at(i+1);
          ans -= stoi(strvec.at(i+1));
          break;
        case '*':
          infix = "(" + infix + ")" + " * " + strvec.at(i+1);
          ans *= stoi(strvec.at(i+1));
          break;
        case '/':
          infix = "(" + infix + ")" + " / " + strvec.at(i+1);
          ans /= stoi(strvec.at(i+1));
          break;
      }
    }
    cout << infix << " = " << ans << endl;
  }
}
*/
