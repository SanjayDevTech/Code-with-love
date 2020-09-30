#include<bits/stdc++.h>

using namespace std;


void SelectionSort(int a[],int n){

    for(int i=0;i<n-1;i++){
        int min_ind=i;
        
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min_ind]){
                min_ind=j;
            }
        }
        swap(a[min_ind],a[i]);
    }
}



int main(){
    int n;
    cout<<"Enter the no of Elements:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements to be sorted:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    SelectionSort(a,n);
    cout<<"Sorted Array:\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}