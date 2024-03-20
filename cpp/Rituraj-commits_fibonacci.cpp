/* This program implements Fibonacci numbers using Binet's Formula

    Binet's Theorem states the nth term of a fibonacci can be determined using the formula:

    phi1= ( 1 + sqrt ( 5 ) )/2

    phi2=( 1 - sqrt ( 5 ) )/2

    
    f ( n ) = ( pow ( phi1 , n ) - pow ( phi2 , n ) ) sqrt ( 5 )
    

   Time Complexity: O(1) */

  

#include<iostream>
#include<cmath>

int fibonacci(int n){
    double phi1=(1+sqrt(5))/2;
    double phi2=(1-sqrt(5))/2;
    int f=round((pow(phi1,n)-pow(phi2,n))/sqrt(5));
    return f;
    


}

int main(){
    int fib=2;
    std::cout<<fibonacci(fib);
    return 0;
}