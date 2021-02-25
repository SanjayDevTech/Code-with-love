#include <iostream>
using namespace std;

int main(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < i; j++){
            cout << " ";
        }
        cout << "Hello, World!\n";
    }
    for(int i = 14; i >= 0; i--){
        for(int j = i; j >= 0; j--){
            cout << " ";
        }
        cout << "Hello, World!\n";
    }
    return 0;
}
