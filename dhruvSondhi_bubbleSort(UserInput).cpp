/* Code for sorting an array using the Bubble Sort Algorithm 
   Made In C++ Language
   Made By Dhruv Sondhi On 03/10/2020
*/

#include <bits/stdc++.h>

using namespace std;

//Function Calling the Bubble Sort Algorithm 
void bubbleSort(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(a[j]>a[j+1]){
            //Swapping the Values in the Array 
                int temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n=0;
    //Taking Input for the number of elements in the array
    cin>>n;
    
    int a[n]={0};
    //Taking inputs in the array thus formed
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    //calling Bubble sort on the Array
    bubbleSort(a,n);
    
    //Displaying the sorted Array 
    cout<<"Sorted Array is: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
