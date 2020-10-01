#include <iostream>
using namespace std;
int main()
{
    int i, j, n;
    cout << "Number Entered should be Odd" << endl;
    cin >> n; // ‘n’ must be odd
    int num1 = n / 2 * 3;
    // Right Arrow
    cout << "Right Arrow" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == n / 2 || j - i == n / 2 || i + j == num1)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    // Left Arrow
    cout << "Left Arrow" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == n / 2 || i - j == n / 2 || i + j == n / 2)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}