#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define lld long long int

struct shape{
    int l,b,h;
};
int n;
shape arr[31],r_arr[93];

/*int compare(shape A,shape B)
{
    return A.l*A.b-B.l*B.b;
}*/

int compare (const void *A, const void * B)
{
    return ( (*(shape *)B).l * (*(shape *)B).b ) -
           ( (*(shape *)A).l * (*(shape *)A).b );
}

int main() {
	// your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lld t;
    //cin>>t;
    while(1)
    {
        cin>>n;

        if(n==0)
        break;

        for(int i=0;i<n;i++)
        cin>>arr[i].l>>arr[i].b>>arr[i].h;

        int j=0;
        for(int i=0;i<n;i++)
        {
            r_arr[j].h=arr[i].h;
            r_arr[j].l=max(arr[i].b,arr[i].l);
            r_arr[j].b=min(arr[i].l,arr[i].b);
            j++;

            r_arr[j].h=arr[i].b;
            r_arr[j].l=max(arr[i].h,arr[i].l);
            r_arr[j].b=min(arr[i].l,arr[i].h);
            j++;

            r_arr[j].h=arr[i].l;
            r_arr[j].l=max(arr[i].b,arr[i].h);
            r_arr[j].b=min(arr[i].h,arr[i].b);
            j++;
        }

        //sort(r_arr,r_arr+3*n,compare);
        qsort (r_arr, 3*n, sizeof(r_arr[0]), compare);

        int lih[3*n+1],res=0;

        for(int i=0;i<3*n;i++)
        {
            lih[i]=r_arr[i].h;
            for(int j=0;j<i;j++)
            {
                if(r_arr[j].l>r_arr[i].l&&r_arr[j].b>r_arr[i].b)
                lih[i]=max(lih[i],r_arr[i].h+lih[j]);
            }
            res=max(res,lih[i]);
        }

        cout<<res<<'\n';
    }
}

