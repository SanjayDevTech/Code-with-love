#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ar[n];
    cout<<"enter the elemnets of array"<<endl;
    for(int i=0;i<n;i++)
    cin>>ar[i];
    int x;
    cout<<"Enter element to be searched";
    cin>>x;
    sort(ar,ar+n);
     if (binary_search(ar, ar + n, x)) 
        cout << "\nElement found in the array"; 
    else
        cout << "\nElement not found in the array"; 
        return 0;
}