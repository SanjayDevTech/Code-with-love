#include <iostream>
using namespace std;

int bubblesort(int array[],int size){
    int temp,i,j;
    for(i=0;i<size-1;i++){
        for(j=0;j<size-i-1;j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    return 0;
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
  