#include <iostream>
using namespace std;

int knapsack(int n,int w,int wt[],int val[])
{
    
    int mat[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            mat[i][j]=0;
        }
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0||j==0)
            {
                mat[i][j]=0;
            }
            else if(wt[i-1]<=w)
            {
                mat[i][j]=max(val[i-1]+mat[i-1][j-wt[i-1]],mat[i-1][j]);
            }
            else
            {
                mat[i][j]=mat[i-1][j];
            }
        }
    }
    return mat[n][w];
}
int main()
{
    int n,W;
    cout<<"Enter the number of items:"<<endl;
    cin>>n;
    int val[n], wt[n];
    cout<<"Enter the weights of the items:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    cout<<"Enter the values of the items:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    cout<<"Enter the total Capacity of Knapsack:"<<endl;
    cin>>W;
    int maxval=knapsack(n,W,wt,val);
    cout<<"The maximum value for the given capacity of Knapsack is:"<<endl<<maxval<<endl;
    return 0;
}