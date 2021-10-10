#include <iostream>
#include <climits>
using namespace std;

int main(){
  int n;
  cin>>n ;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];

  }
  int currSum=0;
  int maxsum=INT_MIN;

for(int i=0;i<n;i++){
  currSum+=arr[i];
  if (currSum<0){
    currSum=0;

  }
  maxsum=max(maxsum,currSum);
  }
cout<<maxsum<<endl;

return 0;
}

// output-:
// ./a.exe
// 4
// 7 5 -9 1
// 12