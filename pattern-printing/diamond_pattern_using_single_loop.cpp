/*In this program I will be showing a program 
how to print a Diamond pattern using a single loop and no if-else block
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  //no of rows to be printed
  cin>>n;

  //as we will be using a single pass loop and no if-else
  //we have to modify our logic to run the loop from -n to n 
  //to print 2 different pattern on aa single pass

  for(int i=-n+1;i<n;i++){
    vector<char> row(2*n-abs(i)-1);
    fill(row.begin(), row.begin()+abs(i),' ');
    fill(row.begin()+abs(i), row.end(),'*');
    string s(row.begin(), row.end());
    cout<<s<<endl;
  }
  return 0;
}