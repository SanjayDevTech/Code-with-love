#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define f(i,n) for(i=0;i<n;i++)
#define fab(i,a,b) for(i=a;i<b;i++)
#define fabr(i,a,b) for(i=b;i>=a;i--)
#define sc second
#define fr first
#define pb push_back
#define pf push_front
#define mp make_pair
#define mod 1000000007
#define N 1000000000
using namespace std;
int main()
{
    FAST;
    ll i,j,n;
      n=17;
      char a[n][n];
      f(i,n)
      {
          f(j,n)
          a[i][j]=' ';
      }
      for(i=n/3;i<=2*n/3;i++)//for upper horizontal line of boundary.
      a[i][0]='.';
      for(i=n/3;i<=2*n/3;i++)//for lower horizontal line of boundary.
      a[i][n-1]='.';
      for(i=n/3;i<=2*n/3;i++)//for left vertical line of boundary.
      a[0][i]='.';
      for(i=n/3;i<=2*n/3;i++)//for right vertical line of boundary.
      a[n-1][i]='.';
      for(i=0,j=n/3-1;i<n/3;i++,j--)//for other lines of boundary.
      a[i][j]='.';
      for(i=2*n/3+1,j=0;i<n;i++,j++)
      a[i][j]='.';
      for(i=0,j=2*n/3+1;i<n/3;i++,j++)
      a[i][j]='.';
      for(i=2*n/3+1,j=n-1;i<n;i++,j--)//for other lines of boundary.
      a[i][j]='.';
      for(j=n/6+1;j<=2*n/6;j++)//for eyes.
      a[n/3+1][j]='@';
      for(j=4*n/6+1;j<=5*n/6;j++)
      a[n/3+1][j]='@';//for eyes.
      for(i=4*n/6,j=n/6+1;i<5*n/6;i++,j++)//for smile.
      a[i][j]='-';
      for(i=4*n/6,j=5*n/6;i<5*n/6;i++,j--)
      a[i][j]='-';
      for(j=2*n/6+1;j<4*n/6;j++)
      a[i][j]='-';//for smile.
      f(i,n)
      {
          f(j,n)
          cout<<a[i][j]<<" ";
          cout<<endl;
      }
    return 0;
    
}
