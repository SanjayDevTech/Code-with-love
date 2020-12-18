#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;

const lld N = 200043;
const lld MOD = 1000000007;

lld add(lld x, lld y)
{
    x =((x%MOD)+(y%MOD))%MOD;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}

lld mul(lld x, lld y)
{
    return ((x%MOD)*(y%MOD))% MOD;
}

lld binpow(lld x, lld y)
{
    lld z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

lld inv(lld x)
{
    return binpow(x, MOD - 2);
}

lld divide(lld x, lld y)
{
    return mul(x, inv(y));
}
//Merge Sort Tree

vector<lld>tree[5*N];
lld A[N];
void build_tree( lld cur , lld l , lld r )
{
     if( l==r )
     {
            tree[cur].push_back( A[ l ] );
            return ;
     }
     lld mid = l+(r-l)/2;
     build_tree(2*cur , l , mid ); // Build left tree
     build_tree(2*cur+1 , mid+1 , r ); // Build right tree
    lld i=0,j=0;
    while(i<tree[2*cur].size() && j<tree[2*cur+1].size())
    {
        if(tree[2*cur][i]<tree[2*cur+1][j])
            tree[cur].push_back(tree[2*cur][i]),i++;
        else
            tree[cur].push_back(tree[2*cur+1][j]),j++;
    }
    while(i<tree[2*cur].size())
        tree[cur].push_back(tree[2*cur][i]),i++;
    while(j<tree[2*cur+1].size())
        tree[cur].push_back(tree[2*cur+1][j]),j++;
}
lld query( lld cur, lld l, lld r, lld x, lld y, lld k)
{
       if( r < x || l > y )
      {
               return 0; //out of range
      }
      if( x<=l && r<=y )
      {
              //Binary search over the current sorted vector to find elements smaller than K
              return lower_bound(tree[cur].begin(),tree[cur].end(),k)-tree[cur].begin();
      }
      lld mid=l+(r-l)/2;
     return query(2*cur,l,mid,x,y,k)+query(2*cur+1,mid+1,r,x,y,k);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t,i,j;
    cin>>t;
    //t=1;
    while(t--)
    {
    lld n;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>A[i];
    build(1,1,n);
    // TO FIND ELEMENTS SMALLER THEN 3 IN GIVEN RANGE
    cout<<query(1,1,n,1,n,3)<<endl;
    }
}
