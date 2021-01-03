#include<iostream>
#include<vector>

vector <int> heapSort (vector <int> &arr) {
  buildMaxHeap(arr);
  vector <int> sortedArr;
  int heapSize = arr.size() - 1;

  for (int i = heapSize; i > 1; i--) {
    sortedArr.push_back(arr[1]);
    swapInt(&arr[1], &arr[i]);
    arr.pop_back();
    maxHeapify(arr, 1);
  }
  sortedArr.push_back(arr[1]);

  return sortedArr;
}

using namespace std;

int main () {
  vector <int> arr = { NULL, 1, 2, 3, 4, 5, 6, 7};
  vector <int> sortedArr = heapSort(arr);

  for (int i = 0; i < sortedArr.size(); i++) cout<<sortedArr[i]<<endl;
}
