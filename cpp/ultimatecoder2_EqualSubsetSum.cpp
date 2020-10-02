/*
Problem: To check if an array can be divided into two subarrays of equal sum
*/

#include<bits/stdc++.h>
using namespace std;
bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        sum/=2;
        //Find subset sum 
        bool arr[201][20001]={0};
        int i=0,j=0;
        for(i=0;i<=nums.size();i++)
        {
            arr[i][0]=1;
        }
        for(i=1;i<=nums.size();i++)
        {
            for(j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                {
                    arr[i][j]=((arr[i-1][j-nums[i-1]]) ||(arr[i-1][j]));
                }
                else
                    arr[i][j] = arr[i-1][j];
            }
        }
        
        return bool(arr[nums.size()][sum]);
    }
int main()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    if(canPartition(nums))
        cout<<"This array can be divided into 2 subarrays of equal sum"<<endl;
    else
    {
        cout<<"Partition not possible"<<endl;
    }
    return 0;
}
