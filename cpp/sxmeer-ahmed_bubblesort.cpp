#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// Bubble Sort
void bubbleSort(ll arr[], ll size)
{
    for (ll i = 0; i < size; i++)
    {
        for (ll j = i; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                ll temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    ll arr[5] = {32, 8, 2, 5, 7};
    bubbleSort(arr, 5);
    cout << "the array after bubble sort is\n";
    for (ll i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
