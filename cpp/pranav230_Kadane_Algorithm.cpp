/*
 * 
 * Author: Pranav Bansal
 * 
*/

#include<bits/stdc++.h>

#define rep(i,a,n) for(int i=a;i<n;i++)

using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	rep(i,0,n)
		cin>>arr[i];
		
	int best = 0, sum = 0;
	
	rep(k,0,n){
		sum = max(arr[k],sum+arr[k]);
		best = max(best,sum);
	}
	
	cout << best << endl;
	
	return 0;
}
