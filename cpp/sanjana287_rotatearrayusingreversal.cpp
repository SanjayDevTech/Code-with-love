// code to rotate array by d elements anticlockwise
#include <bits/stdc++.h>
using namespace std;
void reverse(int a[],int p,int q)
{
    int temp=0;
    int e=(p+q)/2;
    int c=0;
    for(int i=p;i<=e;i++)
    {
        temp=a[i];
        a[i]=a[q-c];
        a[q-c]=temp;
        c++;
    }
}
void rotateArr(int a[], int d, int n){
    // code here
    reverse(a,0,d-1); // reverse first d elements
    reverse(a,d,n-1); // reverse next d elements
    reverse(a,0,n-1); // reverse entire array
}
int main()
{
    int a[]={1,23,28,34,37,56,78,83,89,90};
    int n=10;
    int d=5;
    cout<<"Array before reversal"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    rotateArr(a,d,n);
    cout<<"Array after reversal"<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
