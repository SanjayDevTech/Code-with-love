#include <bits/stdc++.h> 
using namespace std; 
  
// A method to multiply two numbers using Russian Peasant method 
unsigned int russianPeasant(unsigned int a, unsigned int b) 
{ 
    int res = 0;  // initialize result 
    while (b > 0) 
    { 
         if (b & 1) 
             res = res + a; 
         a = a << 1; 
         b = b >> 1; 
     } 
     return res; 
} 
int main() 
{ 
    unsigned int a, b;
    cin>>a>>b;
    cout << russianPeasant(a,b) << endl; 
    return 0; 
} 
