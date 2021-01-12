/*
	Contribution by - andrewflik(github)
	Sieve Of Eratosthenes
	Test code here : https://ideone.com/uZSfs3
*/

#include<bits/stdc++.h>
using namespace std;

const int si = 1e5;
bool primes[si];

void sieve(){
	fill(primes, primes+si, true);
	/* 
		Little optimization pick out all even, and iterate for remaining odds 
	*/
	primes[0] = primes[1] = false;
	for(int i=4; i<si; i+=2)
		primes[i] = false;
	for(int i=3; i<si; i+=2){
		if(primes[i] and (long)i*i < si){
			for(int j=i*i; j<si; j+=i)
				primes[j] = false;
		}
	}
}

int main(){
	sieve();
	for(int i=0; i<si; i++)
		if(primes[i])
			cout << i << " ";
}
