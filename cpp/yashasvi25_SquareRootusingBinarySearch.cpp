//https://www.interviewbit.com/problems/square-root-of-integer/

#include<bits/stdc++.h>
using namespace std ;

int find_sqrt(int n) {
    if(n ==0 || n==1)
        return n;

    int N = n/2;

    int low = 1, high = N;

    while(low<=high){
        long long mid = low + (high - low)/2;

        long square = mid*mid;
        if(square == n || (square < n && ((mid+1)*(mid+1)) > n)){
            return mid;
        }
        else if(square > n){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return 1;
}


int main(){

    int n ;
    cin>>n ;

    int sqrt_n = find_sqrt(n) ;

    cout<<"square root of "<<n<<" is : "<<sqrt_n<<endl ;

}
