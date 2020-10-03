//Code for Implementation Of Insertion Sort in C++
//Made By Dhruv Sondhi on 03/10/2020

#include <bits/stdc++.h>

using namespace std;

//Function for Insertion Sort Implementation
void insertionSort(int a[],int n){
    int temp=0,j=0; // temp variable to store temporary value that needs to be compared & put into the correct position
    for(int i=0;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
}

int main()
{
    //Input for the number of elements in the array
    int n=0;
    cin>>n;

    //Input for the elements in the array
    int a[n]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //calling InsertionSort Function with parameters of array and number of elements
    insertionSort(a,n);
    //Displaying the array after sorting
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
