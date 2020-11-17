#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int flag = 0;
	int num;
	cin >> num;
	//to check if a number is prime we need to check till the sqrt of the number starting from 2.
	for(int i = 2 ; i < sqrt(num) ; i++){
		if(num%i==0){
			flag = 1;
			cout<< "num " << num <<" is not prime"<<endl;
			break;
		}
	}

	if(flag==0 && num!=1){
		cout << "num " << num << " is prime"<<endl;
	}
	if(num==1){
		cout << "num " << num <<" is not prime"<<endl;	
	}
}