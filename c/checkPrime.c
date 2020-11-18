//This code snippet is written to check if any number is prime or not.
//checkPrime function with return type boolean returns true if number is 
//prime else it return false.

#include<stdio.h>
#include<math.h>
#include<stdbool.h>
bool checkPrime(n){
	int s=sqrt(n);
	if(n==1){
		return false;
	}
	else if(n==2){
		return true;
	}
	int i;
	for(i=2;i<=s+1;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void main(){
	int n;
	printf("Enter a number to check if prime number or not :- ");
	scanf("%d",&n);
	bool isPrime;
	isPrime=checkPrime(n);
	if(isPrime){
		printf("The number %d is a prime number.",n);
	}
	else{
		printf("The number %d is not a prime number.",n);
	}
}
