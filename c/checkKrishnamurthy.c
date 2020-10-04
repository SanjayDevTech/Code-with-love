#include<stdio.h>
#include<stdbool.h>
long factorial(n){
	long fact=1;

	while(n>1){
		fact=n*factorial(n-1);	
		return fact;
	}
	return fact;
}

bool isKrishnamurthy(num){
	long temp=num;
	long sum=0;
	int rem;
	while(num>0){
		rem=num%10;
		sum+=factorial(rem);
		num/=10;
	}

	if(sum==temp){
		return true;
	}
	return false;
}
void main(){
	long n;
	printf("Enter a number:- ");
	scanf("%d",&n);
	bool result=isKrishnamurthy(n);
	if(result){
		printf("%d is a Krishnamurthy number.",n);
	}
	else{		
		printf("%d is not a Krishnamurthy number.",n);
	}
}
