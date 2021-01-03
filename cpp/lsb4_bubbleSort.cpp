#include <iostream>
using namespace std;

void bubbleSort(int vector[], int size, int order){

  if(order == 1){
    for(int i=0; i < size-1; i++){
      int flag = 0;

      for(int j=0; j<size-1-i; j++){
        if(vector[j] > vector[j+1]){
          swap(vector[j+1], vector[j]);
          flag = 1;
        }
      }
      if(flag == 0){
        break;
      }
    }
  }

  else if(order == 2){
    for(int i=0; i < size-1; i++){
      int flag = 0;

      for(int j=0; j<size-1-i; j++){
        if(vector[j] < vector[j+1]){
          swap(vector[j+1], vector[j]);
          flag = 1;
        }
      }
      if(flag == 0){
        break;
      }
    }
  }

}

int main() {
  int size;
  int order;

  cout << "Input Array Size:" << endl;
	cin >> size;

	int vector[size];

	cout << "Input the Elements of Array:" << endl;
	for(int i = 0; i < size; i++){
	  cin >> vector[i];
  }

  cout << "Input the Ordering Style: \n 1 - Ascending \n 2 - Descending" << endl;
  cin >> order;

	bubbleSort(vector, size, order);

	cout << "Sorted Array:" <<endl;
	for (int i = 0; i < size; i++) {
		cout << vector[i] << " ";
  }

  return 0;
}
