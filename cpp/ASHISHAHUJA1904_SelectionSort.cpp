#include <iostream>
using namespace std;

int selectionsort(int array[],int size){
    int i,j,pos,temp,min;
    for(i=0;i<size-1;i++){
        pos=i;
        min=array[i];
        for(j=i+1;j<size;j++){
            if(min>array[j]){
                min=array[j];
                pos=j;
            }
        }
        temp=array[i];
        array[i]=array[pos];
        array[pos]=temp;
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
    selectionsort(array,size);
    cout<<"Sorted Array is ";
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}