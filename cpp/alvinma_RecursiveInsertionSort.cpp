#include <iostream> 
using namespace std; 

void insertionSort(int array[], int size){
	if(size <= 1){
		return;
	}
	
	insertionSort(array, size-1);
	
	int last = array[size-1];
	int j = size-2;
	
	while(j >= 0 && array[j] > last){
		array[j+1] = array[j];
		j--;
	}
	array[j+1] = last;
}

int main()
{
    int array[]={1,34,56,78,89,23,83,28,90,37};
    int size=sizeof(array)/sizeof(array[0]);
	
    cout<<"Original Array is ";
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
	
    insertionSort(array,size);
	
    cout<<"Sorted Array is ";
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
	
    return 0;
}