#include<bits/stdc++.h>


using namespace std;

int DeciTOBi(int n)
{
    int ans=0,p=1;
    while(p>0)
    {
        int last_bit=(n&1);
        ans+=p*last_bit;
        p*=10;
        n=n>>1;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<DeciTOBi(n);
    return 0;
}

/*
13
Output
1101
*/
