/* Problem-Task : Write a function that will produce the output from given input. Deduce the login from sample inputs-outputs.
 * Problem Link : https://edabit.com/challenge/64CeZWx5wWhTxhHLL
*/

#include <bits/stdc++.h>
using namespace std;

int mysteryFunc(int num) {
  std::string temp = std::to_string(num);
  std::sort(temp.begin(), temp.end());
  return abs(num - stoi(temp));
}

int main() {
  int num;
  cin>>num;
  cout<<mysteryFunc(num);
  return 0;
}
