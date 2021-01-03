#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	if(n%400==0)
	cout<<"Leap Year\n";
	else if(n%100==0)
	cout<<"Leap Year\n";
	else if(n%4==0)
	cout<<"Leap Year\n";
	else
	cout<<"Not a Leap Year\n";
	return 0;
}