#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;

bool isprime(int x){
  rep(i,2,x/2){
    if(x%i==0){
      return false;
    }
  }
  return true;
}
int main(){
  int x;
  cin >>x;
  if(x<1){
    cout << "invalid call";
    return 0;
  }
  else if(x==1){
    cout << "1 is not prime";
    return 0;
  }
  cout << x<< " is "<< (isprime(x)?"Prime": "Not Prime");
}
