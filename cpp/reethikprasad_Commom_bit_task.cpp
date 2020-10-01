#include<bits/stdc++.h>


using namespace std;

bool odd(int n)
{
    return n&1;
}

int getbit(int n,int i)//to find the i bit of a number
{
    int mask=(i<<1);
    int bit=(n&mask)>0?1:0;
    return bit;
}


int setbit(int n,int i)//to set the i bit of a number
{
    int mask=(i<<1);
    int ans=n|mask;
    return ans;
}


int clearLast_bit(int n,int i)
{
    int mask=(-1<<i);
    return n&mask;
}

int clearRangeItoJ(int n, int i, int j) {
	int ones = (~0);
	int a = ones << (j + 1);
	int b = (1 << i) - 1;
	int mask = a | b;
	int ans = n & mask;
	return ans;

}


int main()
{

    //FOR CLEAR RANGE IF BIT
    /*
    int n = 31;
	int i = 1, j = 3; //from position i+1 to 0
	cout << clearRangeItoJ(n, i, j) << endl;
	*/



    //for clearLast_bit
    /*
    int n=15;
    int i=3;//not the  position but number of bits
    cout<<clearLast_bit(n,i)<<endl;
    */



    //to check odd
    // cout<<odd(n)<<endl;


   // FOR GET AND SET BIT
   /*
    int i;
    cin>>i;
    cout<<getbit(n,i)<<endl;
    n=setbit(n,i);
    cout<<"Ans "<<n<<endl;
    */
/* Output
1
0
Ans 7
*/

    return 0;
}

