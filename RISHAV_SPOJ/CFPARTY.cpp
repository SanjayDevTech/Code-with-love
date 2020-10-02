#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

int R[]={0, 0, -1, 1};
int C[]={-1, 1, 0, 0};
int N;
int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        cin>>N;
        cout<<max(0,N-2)<<'\n';

    }
}

