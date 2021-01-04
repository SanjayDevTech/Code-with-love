#include <stdio.h>

void swap (int vector[], int j){
  int aux = 0;
  aux = vector[j]; 
  vector[j] = vector[j+1]; 
  vector[j+1] = aux;
}

void bubbleSort(int vector[], int size, int order){
  if(order == 1){
    for(int i=0; i < size-1; i++){
      int flag = 0;

      for(int j=0; j<size-1-i; j++){
        if(vector[j] > vector[j+1]){
          swap(vector, j);
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
          swap(vector, j);
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

  printf("Input Array Size:\n");
	scanf("%i", &size);

	int vector[size];

	printf("Input the Elements of Array:\n");
	for(int i = 0; i < size; i++){
	  scanf("%i", &vector[i]);
  }

  printf("Input the Ordering Style: \n 1 - Ascending \n 2 - Descending\n");
  scanf("%i", &order);

	bubbleSort(vector, size, order);

	printf("The sorted array is:\n");
	for (int i = 0; i < size; i++){
    printf("%i ", vector[i]);
  }
  return 0;
}
