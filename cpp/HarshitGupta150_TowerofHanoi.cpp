#include<bits/stdc++.h>
using namespace std;
void toh(int n,int t1d,int t2d,int t3d){
    if(n==0){
        return;
    }
    toh(n-1,t1d,t3d,t2d);
    cout<<n<<"["<<t1d<<" -> "<<t2d<<"]"<<endl;
    toh(n-1,t3d,t2d,t1d);
    
}
int main() {
    int  n,t1d,t2d,t3d;
    cin>> n>>t1d>>t2d>>t3d;
    toh(n,t1d,t2d,t3d);
}
