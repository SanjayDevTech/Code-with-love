
#include <bits/stdc++.h>
using namespace std;
#define l long long int

//  Approach : Expand Around Center
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";
        int len = 0;
        int n = s.size();
        // odd Length;
        for (int mid = 0; mid < n; mid++)
        {
            for (int i = 0; mid - i >= 0 && mid + i < n; i++)
            {
                if (s[mid - i] != s[mid + i])
                    break; // it is very important step

                if (len < 2 * i + 1)
                {
                    len = 2 * i + 1;
                    ans = s.substr(mid - i, len);
                }
            }
        }

        // even length
        for (int mid = 0; mid < n - 1; mid++)
        {
            for (int i = 1; mid - i + 1 >= 0 && mid + i < n; i++)
            {
                if (s[mid - i + 1] != s[mid + i])
                    break; // it is very important step

                if (len < 2 * i)
                {
                    len = 2 * i;
                    ans = s.substr(mid - i + 1, len);
                }
            }
        }

        return ans;
    }
};

int main()
{

    cout << "Enter the Number of test cases" << endl;
    int t;
    cin >> t;
    Solution mysolution;
    while (t-- > 0)
    {

        string s;
        cout << "Enter the String In which You whant find Longest Palindromic Substring" << endl;
        cin >> s;
        cout << "The Longest Palindromic Substring found in Your entered substring is" << endl;
        cout << mysolution.longestPalindrome(s) << endl;
    }
}
