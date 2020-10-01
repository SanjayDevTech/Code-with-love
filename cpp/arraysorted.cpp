#include<iostream>
using namespace std;


int isarraysorted(int arr[],int n)
{
    if(n==1 || n==0)
    {
        return 1;
    }
    if(arr[n-1]<arr[n-2])
    {
        return 0;
    }

    return isarraysorted(arr,n-1);

}



int main()
{
    int arr[100];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {

        cin>>arr[i];
    }

    if(isarraysorted(arr,n))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}
