#include<bits/stdc++.h>
using namespace std;
int ugly(int n){
	long long int u[n];
	u[0]=1;
	int i2=0,i3=0,i5=0;
	int mul2=2;
	int mul3=3;
	int mul5=5;
	long long int next=1;
	for(int i=1;i<n;i++){
		 next=min(mul2,min(mul3,mul5));
		 u[i]=next;
		 if(next==mul2){
		 	i2=i2+1;
		 	mul2=u[i2]*2;
		 }
		 if(next==mul3){
		 	i3=i3+1;
		 	mul3=u[i3]*3;
		 }
		 if(next==mul5){
		 	i5=i5+1;
		 	mul5=u[i5]*5;
		 }
	}
	return next;
	
}
int main(){
	int n;
	cin>>n;
	cout<<ugly(n)<<endl;
}
