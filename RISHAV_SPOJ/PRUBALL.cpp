#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

lld binomialCoeff(int x, int n)
{
    lld sum = 0, term = 1;
    for (int i = 1; i <= n; ++i) {
        term *= x - i + 1;
        term /= i;
        sum += term;
    }
    return sum;
}

int minTrials(int n, int k)
{

    int low = 1, high = k;

    while (low < high) {
        int mid = (low + high) / 2;
        if (binomialCoeff(mid, n) < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    cin>>t;
    while(t--)
    {
        int a,n,k;
        cin>>a>>n>>k;
        cout<<a<<" "<<minTrials(n, k)<<'\n';
    }
}

