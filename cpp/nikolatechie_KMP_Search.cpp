#include <iostream>
#include <vector>
using namespace std;

int n, m;
string t, p;
vector<int> tmp;

void buildArray()
{
    tmp.resize(m);
    int i = 0, j = 1;

    while (j < m)
    {
        while (i > 0 && p[i] != p[j])
            i = tmp[i-1];

        if (p[i] == p[j])
        {
            tmp[j] = i+1;
            ++i, ++j;
        }
        else ++j;
    }
}

void KMP_Search()
{
    int i = 0, j = 0;

    while (i < n)
    {
        while (j > 0 && t[i] != p[j])
            j = tmp[j-1];

        if (t[i] == p[j])
        {
            ++i;
            ++j;

            if (j == m)
                cout << i-m << '\n'; // occurrence found
        }
        else ++i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);


    cin >> t >> p; // text, pattern
    n = t.size();
    m = p.size();
    buildArray();
    KMP_Search();


    return 0;
}