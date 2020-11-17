#include<iostream>

using namespace std;

int Factorial(int n){
if(n == 0){
return 1;
}
return n * Factorial(n-1);
}
int main(){
cout << Factorial(5);
return 0;
}
