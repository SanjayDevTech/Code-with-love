#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
/*
The function MinSubsetSum finds the minimum difference
between two subset sums of an input array.
The function prints the minimum difference and a string
containing zero's and one's which denote the subset assignment
of the elements in the input array where 0's indicate
the first subset and 1's indicate the second subset.
*/
void MinSubsetSum(int num[],int n, int sum, string ind)
{
    string arr[sum+1];
    arr[0]="";
    for(int i=1;i<sum+1;i++)
    {
        arr[i]="-1";
    }
    /*
    Unlike using a matrix in a standard dp approach, 
    two arrays have been taken here to minimize time
    and space complexity
    */
    vector<int> vec;
    vec.push_back(0);
    for(int i=0;i<n;i++)
    {
        long int vsize=vec.size();
        for(int j=0;j<vsize;j++)
        {
            if(vec[j]+num[i]<sum+1)
            {
                arr[vec[j]+num[i]]=arr[vec[j]]+to_string(i);
                vec.push_back(vec[j]+num[i]);
            }
        }
    }
    vec.clear();
    vec.shrink_to_fit();
    int halfsum=sum/2;
    int diff=0;
    int i;
    for(i=halfsum;i>-1;i--)
    {
        if(arr[i]!="-1")
        {
            diff=sum-(2*i);
            break;
        }
    }
    //Prints the minimum difference
    cout<<"The Minimum Difference is: "<<endl<<diff<<endl;
    string fin="";
    int flag=0;
    for(int x=0;x<ind.length();x++)
    {
        flag=0;
        for(int r=0;r<arr[i].length();r++)
        {
            if(arr[i].at(r)==ind.at(x))
            {
                fin+="0";
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            fin+="1";
        }
    }
    //Prints a string for each index of the array
    //Where 0 denotes the first subset and 1 denotes the second subset
    cout<<"The assignment of elements in Two subsets is: "<<endl;
    cout<<fin<<endl;
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array: "<<endl;
    cin>>n;
    cout<<"Enter the elements in the array: "<<endl;
    int arr[n],sum=0;
    string in="";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        in+=to_string(i);
    }
    MinSubsetSum(arr,n,sum,in);
    return 0;
}