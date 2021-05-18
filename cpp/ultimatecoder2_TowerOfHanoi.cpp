#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void no_moves(int disc_left,int from,int to, int aux)
{
    if(disc_left==1)
        {
            cout << "Move disk 1 from rod " << from<<
                            " to rod " << to<<endl;
                cnt++;
                return;

        }
        no_moves(disc_left-1,from,aux,to);
         cout << "Move disk " << disc_left << " from rod " << from<<
                                " to rod " << to << endl;
                                cnt++;
        no_moves(disc_left-1,aux,to,from);
}
int main()
{
    int n;
    cout<<"Enter number of discs"<<endl;
    cin>>n;
    no_moves(n,1,3,2);
    cout<<"Total number of moves are "<<cnt<<endl;
}
/*
For Understanding Purpose only
1) 4 a c b
2) 3 a b c
3)2 a c b
4) 1 a b c
5)Displayed for moving disc 1
6)Displayed for moving disc 2
7) 1 b c a
8)Displayed for moving disc 1
9)Displayed for moving disc 3
10)2 c b a
11) 1 c a b
12)Displayed for moving disc 1
13) Displayed for moving disc 2
14)1 a b c
15) Displayed for moving disc 2
16) Displayed for moving disc 4
17)3 b c a
18)2 b a c
19)1 b c a
20)Displayed for moving disc 1
.......so on
*/