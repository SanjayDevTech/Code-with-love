// C program to implement Recursive Binary Search 
#include<stdio.h>
void readArray(int array[], int size);
void printArray(int array[], int size);
void bubbleSort(int array[], int size);
int rbs(int array[],int low,int high, int key);
int main()
{
int array[10], n, key, index, start = 0;
printf("Enter the number of elements in array: ");
scanf("%d", &n);
// Read Array
readArray(array, n);

printf("\nEnter the element to be searched: ");
scanf("%d", &key);

// Sorting the array in ascending order
bubbleSort(array, n);

index = rbs(array, start, n, key); 
if(index == -1)
 printf("\nElement is not present in the array. \n");
else printf("\nElement %d is present at index position %d. \n", array[index], index); 

// Print Array
printf("Sorted Array: \n");
printArray(array, n);

return 0;
}

// Read Array
void readArray(int array[], int size){
int i;
for(i=0;i<size;i++){
printf(" Enter the element array[%d]: ", i);
scanf("%d", &array[i]);
}
}

// Print Array
void printArray(int array[], int size){
int i;
for(i=0;i<size;i++)
printf("\narray[%d]: %d",i,array[i]);
printf("\n");
}

// Bubble Sort
void bubbleSort(int array[], int size){
int i, j, temp;

for(i=0;i<size;i++){
for(j=0;j<size-i-1;j++){
if(array[j]>array[j+1]){
temp = array[j];
array[j] = array[j+1];
array[j+1]=temp;
}
}
}
}

// Recursive Binary Search
int rbs(int array[], int low,int high, int key)
{
int mid = (low + high) / 2;
if(low > high)
return (-1);
else if(key == array[mid])
return mid;
else if(key < array[mid])
return rbs(array, low, mid-1, key);
else return rbs(array, mid+1, high, key); 
}

