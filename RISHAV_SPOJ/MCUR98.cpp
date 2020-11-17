#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    bool arr[1000000];
    memset(arr, true, sizeof(arr));


    int i,k,j;
    for(i=1;i<1000000;i++)
    {
        int val=i;
        int sum=0;
        while(val>0)
        {
            sum+=val%10;
            val/=10;
        }
        if(sum+i<1000000)
        {
            sum+=i;
            arr[sum]=false;
        }
    }
    for(i=1;i<1000000;i++)
    if(arr[i])
    cout<<i<<endl;
 return 0;
}

