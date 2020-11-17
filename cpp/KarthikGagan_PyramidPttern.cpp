#include <iostream>
using namespace std;

int main()
{
    int space, r;

    cout <<"Enter number of rows: ";
    cin >> r;

    for(int i = 1, k = 0; i <= r; ++i, k = 0)
    {
        for(space = 1; space <= r-i; ++space)
        {
            cout <<"  ";
        }

        while(k != 2*i-1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }    
    return 0;
}