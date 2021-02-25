#include <iostream>
using namespace std;

void bubblesort(int array[],int size){
    if (size == 1){
		return;
	}
	
	int temp;
	for(int i = 0; i < size-1; i++){
		if(array[i] > array[i+1]){
			temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
		}
	}
	
    bubblesort(array, size-1);
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
	
    bubblesort(array,size);
	
    cout<<"Sorted Array is ";
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
	
    return 0;
}