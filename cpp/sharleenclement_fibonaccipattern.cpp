#include <iostream>
using namespace std;

int main()
{
    int n, sum=0, i, j;
    cin >> n;
    int a = 0, b = 1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            cout << a << "\t";
            sum = a + b;
            a = b;
            b = sum;
            
        }
        cout << "\n";
    }
    return 0;
}