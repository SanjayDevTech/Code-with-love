#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);

    bool arr[87000008];
    memset(arr, true, sizeof(arr));
    for(long i=2;i<sqrt(87000008);i++)
    {
        if(arr[i]==true)
        {
            for(long j=i*i;j<87000008;j+=i)
            arr[j]=false;
        }
    }
    vector <int> res;
    for(long i=2;i<87000008;i++)
    if(arr[i])
    res.push_back(i);

	int t;
	cin>>t;
	while(t--)
	{
	    int k;
	    cin>>k;
	    k--;
	    cout<<res[k]<<endl;
	}
	return 0;
}
