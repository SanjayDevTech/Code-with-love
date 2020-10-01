
// Linear search algorithm
// Using iterative method

#include<iostream>
#include<vector>

using namespace std;

// Linear search function
void linear_search(int arr[], int high , int key){
    
    for(int i=0; i<high ; i++){
        // Condition when key matches with element
        if(arr[i] == key){
            // Printing found and returning to main after our first match
            cout << "\nMatch found on index : " << i;
            return;
        }
    }
    //If key is not found
    cout << "\nNot found";
}

int main(){
    int n,key;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[100];

    //Inputting vector
    cout << "\nEnter the elements in array ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    //Inputting key to be searched
    cout << "\nEnter the number you want to search : ";
    cin >> key;

    //Function call for linear search
    linear_search(arr,n,key);

    return 0;
}