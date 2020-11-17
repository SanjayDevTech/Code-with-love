#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    int A[1000001]={0};

    int i,k,j;
    for(i=2;i<=100;i++)
    {
        if(A[i]==0)
        {
            k=i*i*i;
            for(j=k;j<=1000000;j+=k)
            A[j]=-1;
        }
    }
    k=1;
    for(i=1;i<=1000000;i++)
    if(A[i]==0)
    A[i]=k++;

	int t,n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        scanf("%d",&n);
        if(A[n]!=-1)
        printf("Case %d: %d\n",i,A[n] );
        else
        printf("Case %d: Not Cube Free\n",i);
    }
 return 0;
}

