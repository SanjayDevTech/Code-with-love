#include<bits/stdc++.h>

using namespace std;


int Ternary_Search(int arr[],int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;
        if(arr[mid1]==x)
            return mid1;
        if(arr[mid2]==x)
            return mid2;
        if(x<arr[mid1])
            return Ternary_Search(arr,l,mid1-1,x);
        else if(x>arr[mid2])
            return Ternary_Search(arr,mid2+1,r,x);
        else
            return Ternary_Search(arr,mid1+1,mid2-1,x);

    }
    return -1;
}


int main(){
      int n,x;
    cout<<"Enter the no of Elements:\n";
    cin>>n;
    int a[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Enter the element to be searched in the array:\n";
    cin>>x;
    int p=Ternary_Search(a,0,n-1,x);
    if(p==-1)
    cout<<"Element does not exist\n";
    else{
        cout<<"Element found at index "<<p+1<<"\n";
    }


}