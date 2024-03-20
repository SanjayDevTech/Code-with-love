#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

lld n,ea,s,sp;
lld emp[26],dp[26][300];

lld fun(int month, int e)
{
    if(month==n+1)
    return dp[month][e]=0;

    else if(dp[month][e]!=-1)
    return dp[month][e];

    else if(e<=emp[month])
    return dp[month][e] = ea*(emp[month]-e) + emp[month]*s + fun(month+1,emp[month]);

    else if(e>emp[month])
    {
        lld val = fun(month+1,e) + s*e;
        int j=1;
        for(int i=e-1;i>=emp[month];i--)
        {
            val=min( val , sp*j + fun(month+1,e-j) + s*(e-j) );
            j++;
        }
        return dp[month][e]=val;
    }
}

//-4%3=-1
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t=0;
    //cin>>t;
    //t=1;
    while(1)
    {
        t++;
        cin>>n;
        if(n==0)
        break;

        cin>>ea>>s>>sp;

        for(int i=1;i<=n;i++)
        cin>>emp[i];

        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<t<<", cost = $"<<fun(1,0)<<" "<<'\n';

        /*for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=15;j++)
            cout<<dp[i][j]<<" ";
            cout<<'\n';
        }*/
    }
}

