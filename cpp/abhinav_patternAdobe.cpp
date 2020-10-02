/*  It is a pattern printing problem asked in Adobe.

Given an integer n, you need to print the following pattern pattern.

n=4
      Output :
       4444444
       4333334
       4322234
       4321234
       4322234
       4333334
       4444444

n=3
        Output :
         33333
         32223
         32123
         32223
         33333

*/

#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int nn=2*n-1;
	    int start=0,end=nn-1;
	    int a[nn][nn];
	    while(n>0)
	    {

	        for(int i=start;i<=end;i++)
	        {
	            for(int j=start;j<=end;j++)
	            {
	                if(i==start || i==end || j==start|| j==end)
	                a[i][j]=n;
	            }
	        }
	        n--;
	        start++;
	        end--;
	    }
	    for(int i=0;i<nn;i++)
	    {
	        for(int j=0;j<nn;j++)
	        cout<<a[i][j];
	        cout<<"\n";
	    }
	    
	}
	return 0;
}
