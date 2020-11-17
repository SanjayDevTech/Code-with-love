// Problem statement: Create a function that takes two numbers as arguments and returns the Greatest Common Devisor (GCD) of the two numbers.
// Probelm Link: https://edabit.com/challenge/BzEQsTSmPATbsZJCR
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	return std :: __gcd(a, b);
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	return 0;
}
