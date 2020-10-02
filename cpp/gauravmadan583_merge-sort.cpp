#include<bits/stdc++.h>
using namespace std;
vector<int> merge(vector<int> arr1, vector<int> arr2){
    vector<int> arr;
    int i=0, j=0;
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            arr.push_back(arr1[i++]);
        }else{
            arr.push_back(arr2[j++]);
        }
    }

    if(i<arr1.size()){
        while(i<arr1.size()){
            arr.push_back(arr1[i++]);
        }
    }else{
        while(j<arr2.size()){
            arr.push_back(arr2[j++]);
        }
    }

    return arr;
}
vector<int> mergeSort(vector<int> &arr){
    if(arr.size()<=1) return arr;
    int mid = arr.size()/2;
    vector<int> arr1(arr.begin(), arr.begin()+mid);
    vector<int> arr2(arr.begin()+mid, arr.end());

    arr1 = mergeSort(arr1);
    arr2 = mergeSort(arr2);

    arr = merge(arr1, arr2);

    return arr;
}
int main(){
    int testcases;
    cout<<"Enter the number of testcases: ";
    cin>>testcases;
    while(testcases--){
        int n;
        cout<<"Enter the number of elements: ";
        cin>>n;
        vector<int> arr(n, 0);
        cout<<"Enter the elements: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        arr = mergeSort(arr);

        cout<<"The sorted array is: ";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}