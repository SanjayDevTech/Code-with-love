#include <iostream>
#include <vector>

using namespace std;

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
    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    int m;
    cin >> m;
    vector<int> v1(m);
    for(int i = 0; i < m; i++){
        cin >> v1[i];
    }
    for(int i = 0; i < m; i++){
        cout << binary(v, 0, n-1, v1[i]) << " ";
    }

    return 0;
}