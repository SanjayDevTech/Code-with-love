#include <bits/stdc++.h>
using namespace std;

#define lld long long int

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        lld n,b;
        cin>>n>>b;
        lld arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        lld cnt=0,sum=0,rcnt=0,rsum=0,ptr=0;
        vector <int> v;
        for(int i=0;i<n;i++)
        {
            if(arr[i]+sum<=b)
            {
                v.push_back(i);
                sum+=arr[i];
                cnt++;
                if(rcnt<cnt)
                {
                    rcnt=cnt;
                    rsum=sum;
                }
                if(rcnt==cnt&&rsum>sum)
                rsum=sum;
            }
            else
            {
                while(sum+arr[i]>b&&ptr<v.size())
                {
                    sum-=arr[v[ptr]];
                    ptr++;
                    cnt--;
                }
                if(sum+arr[i]<=b)
                {
                    v.push_back(i);
                    sum+=arr[i];
                    cnt++;
                }
                if(rcnt==cnt&&rsum>sum)
                rsum=sum;
            }
        }
        cout<<rsum<<" "<<rcnt<<"\n";
    }
}


