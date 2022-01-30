#include <iostream>

using namespace std;

int findMax(int arr[], int n){
int max = arr[0];
for(int i = 0; i < n; i++){
if(max < arr[i]){
    max = arr[i];
    } 
  }
  return max;
}
int main(){
int arr[] = {2, 1, 7, 4, 5, 3, 6};
cout << findMax(arr, 7);
}
