#include<stdio.h>
#include<stdlib.h>
int findMax(int A[], int n){
    int i,max;
    max=A[0];
    for(i=1;i<n;i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    return max;
}
void countSort(int A[], int n){
    int max,i,j;
    int *count;
    max=findMax(A,n);  
    count=(int *)malloc(sizeof(int));  
    for(i=0;i<(max+1);i++){
        count[i]=0;
    }
    for(i=0;i<n;i++){
        count[A[i]]++;
    }
    i=0,j=0;
    while(i<(max+1)){
        if(count[i]>0){
            A[j]=i;
            j++;
            count[i]--;
        }
        else
        {
            i++;
        }   
    }
}

int main(){
    int n,i,A[10];
    printf("Enter n");
    scanf("%d",&n);
    printf("Enter array element");
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int max;
    countSort(A,n);
    printf("After sorting\n");
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}

// it is a space consuming algorithm
// in count sort we take a array with size of maximum element present in initial array
// in count array, number of occurence will be stored 
// f(n)=O(n)