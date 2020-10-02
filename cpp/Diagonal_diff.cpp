/*Given a square matrix, 
calculate the absolute difference between the sums of its diagonals.
*/

#include <bits/stdc++.h>
#include<cmath>

using namespace std;

int main() {
    int n,a[200][233];
    int sumA = 0,sumB = 0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }

    }

for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                sumA = sumA+a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==n-j-1)
            sumB = sumB+a[i][j];
        }
    }
   
    cout<<abs(sumA-sumB);

    return 0;
}

