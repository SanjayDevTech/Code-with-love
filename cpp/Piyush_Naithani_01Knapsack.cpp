#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, x; cin >> n >> x;
    vector <int> price(n+1), pages(n+1);
    for (int i = 1; i <= n; ++i) //cost/weight
        cin >> price[i];
    for (int i = 1; i <= n; ++i) 
        cin >> pages[i];  //value..

    //dp[i][j] => using elements [1..i], maximum value I can get if current weight is 'j'
    //to do the above job correctly, here is the recurrence relation, which is based on "use it" or "not"
    //dp[i][j] = max(dp[i-1][j], pages[i] + dp[i-1][j-price[i]]); //max(dont use current one, use the current one)
    vector <vector <int>> dp(n+1, vector <int> (x+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= x; ++j) {
            dp[i][j] = dp[i-1][j]; // not ith book
            int left = j - price[i];
            if (left >= 0)
                dp[i][j] = max(dp[i][j], pages[i] + dp[i-1][left]); //include the ith book
        }
    }

    cout << dp[n][x];


    return 0;
}

//https://cses.fi/problemset/task/1158

//Note: above algorithm assumes one item only once, not multiple occurence
// to allow multiple occurrence you just do, =>pages[i] + dp[i][left]
//problem: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0/

//https://atcoder.jp/contests/dp/tasks/dp_d
//sol: https://atcoder.jp/contests/dp/submissions/14115284

//https://atcoder.jp/contests/dp/tasks/dp_e  (knapsack with W <= 1e9)
//https://atcoder.jp/contests/dp/submissions/14384195

