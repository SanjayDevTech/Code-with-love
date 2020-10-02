#include<iostream>
using namespace std;
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int start,int end){
	int pivot=arr[end];
	int i=start-1;
	for(int j=start;j<=end-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
		
	}
	swap(&arr[i+1],&arr[end]);
	return i+1;
}
void quicksort(int arr[],int start,int end){
	if(start<end){
		int pi=partition(arr,start,end);
		quicksort(arr,start,pi-1);
		quicksort(arr,pi+1,end);
	}
}

int main(){
	
	int arr[]={30,60,5,10,15,3};
	quicksort(arr,0,5);
	for(i=0;i<6;i++){
		cout<<arr[i]<<endl;
	}
	
}
