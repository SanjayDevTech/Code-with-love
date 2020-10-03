#include<iostream>
#include<vector>
using namespace std;
int main(){
	int k;
	int N;
	vector<int>A;
	cin >> N;
	//enter elements in sorted order
	for(int i = 0 ; i < N ; i++){
		int a;
		cin >> a;
		A.push_back(a);
	}
	//num to be searched in array A
	cin >> k;
	int l,r;
	l = 0;
	r = A.size()-1;
	while(l <= r){
		int mid = l+(r-l)/2;
		if(A[mid] >= k){
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	if(A[l]==k){
		cout << "number " << k <<" found in array" << endl;
	}
	else{
		cout << "number not found in array"<<endl;
	}
}