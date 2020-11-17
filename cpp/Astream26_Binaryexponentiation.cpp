#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define loop(i,n) for(i=0;i<n;i++)
//#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define ci(x)    scanf("%d",&x)
#define cl(x)    scanf("%lld",&x)
#define cs(s)    scanf("%s",s)
#define ptfi(x)    printf("%d\n",x)
#define ptfl(x)    printf("%lld\n",x)
#define ptfs(s)    printf("%s\n",s)
#define dbg(x) cout << #x << "=" << x << endl
#define dbg2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>    pai;
typedef pair<ll, ll>    pal;
typedef vector<int>        vei;
typedef vector<ll>        vel;
typedef vector<pai>        vpai;
typedef vector<pal>        vpal;
typedef vector<vei>        vvi;
typedef vector<vel>        vvl;
const int mod = 1'000'000'007;

ll power(ll a,ll b){
    ll res=1;

    if(b==0)
        return res;
    while(b>0){
        if(b%2==0){
            a = a*a;
            b = b/2;
        }
        else{
             res = res*a;
             b = b-1;
        }
    }

    return res;
}
int main() {
   // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout<<"CPP PROGRAM OF Binary exponentiation\n";

  cout<<"NO OF TESTCASES: ";
    int t;
  cin>>t;
  for(int l=0;l<t;++l){
       ll a,b;
       cout<<"ENTER A AND B"<<endl;

       cin>>a>>b;
       ll res = power(a,b);
       cout<<"RESULT:"<<res<<endl;

  }

    return 0;
}

