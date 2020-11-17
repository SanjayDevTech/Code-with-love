/**Printing Matrix in Spiral Form**/
#include<iostream>
using namespace std;

int main()
{
	int t;

	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        int A[n][n];
        int len=n,k=1,p=0,i;
        while(k<=n*n)
        {
            for(i=p;i<len;i++)
            {
                A[p][i]=k++;
            }
            for(i=p+1;i<len;i++)
            {
                A[i][len-1]=k++;
            }
            for(i=len-2;i>=p;i--)
            {
                A[len-1][i]=k++;
            }
            for(i=len-2;i>p;i--)
            {
                A[i][p]=k++;
            }
            p++,len=len-1;

        }
        if(!n%2)
        {
            A[(n+1)/2][(n+1)/2]=n*n;
        }
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<A[i][j]<<" ";
            }
            cout<<endl;
        }
    }
	return 0;
}
/**
Output:
3
5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
3
1 2 3
8 9 4
7 6 5
2
1 2
4 3

Process returned 0 (0x0)   execution time : 19.720 s
Press any key to continue.
**/
