#include<bits/stdc++.h>
using namespace std;

int dp[1000000];

//Driver program
int main()
{
    int t,pig,bank,coin,i;
    cin>>t;
    while(t--)
    {
        int start,yr,d;
        cin>>start>>yr>>d;
        int wt[d+1],val[d+1];
        for(int i=0;i<d;i++)
        {
            cin>>wt[i]>>val[i];
            wt[i]/=1000;
        }
        int rem=start%1000;
        start/=1000;
        int sum=start;
        for(int i=1;i<=yr;i++)
        {
            for(int i=0;i<=sum;i++)
            dp[i]=0;

            for(int j=1;j<=sum;j++)
            {
                for(int k=0;k<d;k++)
                {
                    if(wt[k]<=j)
                    dp[j]=max(dp[j],dp[j-wt[k]]+val[k]);
                }
            }
            start=start+(dp[sum]+rem)/1000;
            rem=(dp[sum]+rem)%1000;
            sum=start;
            //cout<<start<<" "<<i<<"\n";
        }
        cout<<start*1000+rem<<"\n";
    }
}
