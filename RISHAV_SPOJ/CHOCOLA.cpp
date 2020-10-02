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

//-4%3=-1
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int x[m],y[n];
        for(int i=0;i<m-1;i++)
        cin>>x[i];
        for(int i=0;i<n-1;i++)
        cin>>y[i];

        sort(x,x+m-1,greater <int>());
        sort(y,y+n-1,greater <int>());

        int i=0,j=0,r=1,c=1;
        int ans=0;
        while(i<m-1&&j<n-1)
        {
            if(x[i]>y[j])
            {
                ans+=c*x[i];
                i++;
                r++;
            }
            else
            {
                ans+=r*y[j];
                j++;
                c++;
            }
        }
        if(i<m-1)
        {
            while(i<m-1)
            {
                ans+=c*x[i];
                i++;
            }
        }
        if(j<n-1)
        {
            while(j<n-1)
            {
                ans+=r*y[j];
                j++;
            }
        }
        cout<<ans<<"\n";
    }
}

