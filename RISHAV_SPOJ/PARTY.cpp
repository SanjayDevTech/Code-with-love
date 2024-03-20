#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int sum,n;
int wt[101],val[101];
void fun(int W, int n)
{
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +  K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    int res = K[n][W];
    int v=res;

    w = W;
    int cap=0;
    /*for (i = n; i > 0 && res > 0; i--)
    {
        if (res == K[i - 1][w])
            continue;
        else {

            cap+=wt[i-1];
            res = res - val[i - 1];
            w = w - wt[i - 1];
        }
    }*/
    for(int i=0;i<=W;i++)
    if(K[n][i]==res)
    {
        cap=i;
        break;
    }
    cout<<cap<<" "<<v<<"\n";
}
int main()
{
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(1)
    {
        cin>>sum>>n;

        if(sum==0&&n==0)
        break;

        for(int i=0;i<n;i++)
        cin>>wt[i]>>val[i];

        //memset(K,-1,sizeof(K));
        fun(sum,n);

    }
}
