#include <bits/stdc++.h>
#include <iostream> 
using namespace std;

int KNAPSACK(int wt[],int val[],int w ,int n){
	if(n==0||w==0){
		return 0;
	}
	if(wt[n-1]<=w){
		return max(val[n-1]+KNAPSACK(wt,val,w-wt[n-1],n-1),KNAPSACK(wt,val,w,n-1));
		
	}
	else if(wt[n-1]>w){
		return KNAPSACK(wt,val,w,n-1);
		
	}
}
int main(){
	int w,n;
	cout<<"enter the number of element:"<<endl;
	cin>>n;
	cout<<"enter the capacity: "<<endl;
	cin>>w;
	int wt[n],val[n];
	cout<<"enter the item weight: "<<endl;
	for(int i=0;i<n;i++){
		cin>>wt[i];
	}
	cout<<"enter the  items value:"<<endl;
	for(int i=0;i<n;i++){
		cin>>val[i];
	}
	
	cout<<KNAPSACK(wt,val,w,n);
	return 0;
	
	
}
