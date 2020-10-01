#include <iostream>

using namespace std;

void merge (int arr[], int l , int mid, int r){
    int i,j,k;
    int n1 = mid - l + 1, n2 = r - mid;

    // Temporary arrays
    int *t1 = new(nothrow) int[n1], *t2 = new(nothrow) int [n2];
    
    // Updating values of temporary arrays
    for(int i = 0; i < n1; i++){
        *(t1 + i) = *(arr + l + i);
    }
    for(int j = 0; j < n2; j++){
        *(t2 + j) = *(arr + mid + 1 +j);
    }

    i = 0, j = 0, k = l;
    //Updating original array
    while(i < n1 && j <n2){
        if(*(t1 + i) < *(t2 + j)){
            *(arr + k) = *(t1 + i);
            i++;
        }
        else{
            *(arr + k) = *(t2 + j);
            j++;
        }
        k++;
    }

    // If temp2 is exhausted
    while(i < n1){
        *(arr + k) = *(t1 +i);
        i++;
        k++;
    }
    // If temp1 is exhausted
    while(j < n2){
        *(arr + k) = *(t2 +j);
        j++;
        k++;
    }

}

void mergesort(int arr[], int l, int r){
    if(l < r){
        // Dividing array and getting the mid point
        int mid = l+ ((r-l)/2);

        // Merge sort function for divided array
        mergesort(arr , l, mid);
        mergesort(arr, mid + 1, r);

        // Mergind arrays
        merge(arr, l, mid, r);

    }
}

int main(){
    int n;
// Inputting the size of array
    cout << endl << "Enter size : ";
    cin >> n;

// Array decleration and inputting values
    int *arr = new(nothrow) int[n];
    if(!arr){
        cout << endl << "Memeory allocation failed ";
        return 0;
    }
    cout << endl << "Enter element into array ";
    for(int i = 0; i < n; i++){
        cin >> *(arr + i);
    }

   // mergesort function
    mergesort(arr, 0, n-1);

// Printing sorted array
    cout << endl << "Sorted array : ";
    for(int i = 0; i<n; i++){
        cout << *(arr + i) << "  ";
    }
    

    return 0;
}