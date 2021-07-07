#include <iostream>
using namespace std;

int main()
{
    int n;
    unsigned long factorial = 1;

    cout<<"Enter the number whom you want to find the factorial of: ";
    cin>>n;

    for(int i = 1;i<=n;i++)
    {
        factorial *= i;
    }

    cout<<"The Factorial of " << n << " is " << factorial;    
    return 0;
}