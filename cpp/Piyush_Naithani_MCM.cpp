#include<bits/stdc++.h>
using namespace std;

//NOTE: n = size of p[]
//Number of matrices = n-1
//p[] = array for orders
//order of ith A[i] => p[i-1]*p[i], i = 1,2....


int MCM(int p[],int n){
    int mp[n][n];

    //Self multiplication costs = 0
    for (int i = 1; i < n; i++)
        mp[i][i] = 0;

    // L = number of matrices to be multiplied
    //total number of matrices is n - 1
    //so, l = [2, n-1]
    for (int l = 2; l < n; ++l){
        for (int i = 1; i < n-l+1; ++i){
            int j = i + l - 1;

            //i, j will be two pointer to point
            mp[i][j] = INT_MAX;

            //Intermediate point = k
            for (int k = i; k < j; ++k){
                int q = mp[i][k] + mp[k+1][j] + p[i-1]*p[k]*p[j];

                if (q < mp[i][j])
                    mp[i][j] = q;
            }
        }
    }

    return mp[1][n-1];

}


int main(){

    int p[] = {1,2,3,4};
    int n = sizeof(p)/sizeof(p[0]);
    cout << MCM(p, n);
}

//practice Problems:

 //https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0
//https://www.codechef.com/PRACTICE/problems/CIRMERGE   (Circular Merge, Same as Matrix chain Multiplication, 
//(by doubling the array) https://www.codechef.com/viewsolution/37386387
// (by just using mod) https://www.codechef.com/viewsolution/37387318)

//https://codeforces.com/gym/102644
