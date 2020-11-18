/*Unique_Number_III
Given an array that contains all elements occurring 3 times, but one occurs only once. Find that unique element.*/
#include <iostream>
using namespace std;
int main() {
	int n;
	cin>>n;

	int ones=0,twos=0,threes=0;

	for(int i=0;i<n;i++) {
		int no;
		cin>>no;
		twos |= (ones & no);
		ones ^= no;
		threes = (ones & twos);
		ones &= ~threes;
		twos &= ~threes;
	}
	cout<<ones;
	return 0;

}
/*
Input : arr[] = {6, 2, 5, 2, 2, 6, 6}
Output : 5	
Time Complexity:O(n)
*/
