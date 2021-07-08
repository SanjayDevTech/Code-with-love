#include <iostream>
#include <vector>
using namespace std;


vector<int> Z;
int n;
string txt, pat, s;

void build()
{
    Z.resize(n);
    Z[0] = n;
    int L = 0, R = 0;

    for (int t1 = 1; t1 < n; ++t1)
    {
        if (t1 > R)
        {
            L = R = t1;

            while (R < n && s[R-L] == s[R]) ++R;
            Z[t1] = R-L;
            --R;
        }
        else
        {
            int k = t1-L;

            if (Z[k] < R-t1+1)
                Z[t1] = Z[k];
            else
            {
                L = t1;

                while (R < n && s[R-L] == s[R]) ++R;
                Z[t1] = R-L;
                --R;
            }
        }
    }
}

void search()
{
    if (pat.size() > txt.size()) return; // pattern doesn't occurr in text
    s = pat + '$' + txt; // character '$' should NOT be present neither in pat nor txt
    n = s.size();
    build();

    for (int t1 = 0; t1 < n; ++t1)
    {
        if (Z[t1] == pat.size())
            cout << "Occurence found at index " << t1-pat.size()-1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> txt >> pat;
    search();



    return 0;
}