#include <iostream>
using namespace std;
int main(){
	int yr;
	cin >> yr;
	if(yr%4 == 0){
		if(yr%100==0){
			if(yr%400==0){
				cout << yr << " is a leap year" << endl;
			}
			else{
				cout << yr << " is not a leap year"<<endl;
			}
		}
		else{
			cout << yr << " is a leap year"<<endl;
		}
	}
	else{
		cout << yr << " is not a leap year"<<endl;
	}
	return 0;
}