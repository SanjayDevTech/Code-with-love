#include <bits/stdc++.h>

using namespace std;
int LCS(string s1, string s2){
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
    for(int i = 1; i<=s1.length(); i++){
        for(int j = 1; j<= s2.length(); j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+ dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[s1.length()][s2.length()];
}
int main()
{
    string s1, s2;
    cin>>s1;
    cin>> s2;
    int res = LCS(s1,s2);
    cout<< res<<endl;
    return 0;
}
