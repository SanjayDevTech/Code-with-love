//CPP program for unbounded knapsack with minimization
#include<bits/stdc++.h>
using namespace std;
#define MX 1000000

//returns min value of knapsack with capacity w
void unboundedKnapsack_min(int w,int val[],int wt[],int n)
{
    int dp[w+1],i,k;

    //storing maximum value
    for(i = 1; i < w + 1; i++)
        dp[i] = MX;

    dp[0] = 0;
    for(i = 1; i <= w; i++)
    {
        for(k = 0; k < n; k++)
        {
            if(wt[k] <= i)
            {
                dp[i] = min( dp[i], dp[i-wt[k]]+val[k] );
            }
        }
    }
    if(dp[w]==MX)
    cout<<"This is impossible.\n";
    else
    cout<<"The minimum amount of money in the piggy-bank is "<<dp[w]<<".\n";
}
//Driver program
int main()
{
    int t,pig,bank,coin,i;
    cin>>t;
    while(t--)
    {
        cin>>pig>>bank>>coin;
        int val[coin+1],wt[coin+1];
        int w= bank-pig;
        for(i=0;i<coin;i++)
            cin>>val[i]>>wt[i];
        unboundedKnapsack_min(w,val,wt,coin);
    }
}
