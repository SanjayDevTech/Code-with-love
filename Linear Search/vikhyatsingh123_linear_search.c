
// Linear Search in C++
// date- 03-10-2020
// code changed from C to c++ with some minor changes
#include <stdio.h>
#include<iostream.h>
int search(int array[], int n, int x) {
  
  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = 1;
  int n = sizeof(array) / sizeof(array[0]);  // calculates size of array
  
  // function call 
  int result = search(array, n, x);
   
  // used if-else instead of ternary operator
  if(result == -1){
    cout<<"element not found !"<<endl;
   }else{
    cout<<"element found at"<< i <<"index"<<endl;
   }
}

// time complexity----> o(n)    as the search happens sequentially
