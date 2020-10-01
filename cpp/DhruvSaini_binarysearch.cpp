#include <iostream>
#include <vector>

using namespace std;

// Binary Search Function
int binary(vector<int> v, int low, int high, int key){
    while(low <= high){
        int mid = low + ((high - low) / 2);
        if(v[mid] == key){
            return mid;
        }
        
        if(v[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    // Returning -1 if element is not found
    return -1;
}

int main(){
    int n;
    cout << "Enter the size : ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter elements[In ascending order] : ";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int key;
    cout << "Enter key to be searched : ";
    cin >> key;

    // Searched Element
    int res = binary(v, 0, n-1, key);
    if(res == -1){
        cout << "Key not found ";
    }
    else{
        cout << "Key found at index : " << res << endl;
    }

    return 0;
}