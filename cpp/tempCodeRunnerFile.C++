
#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b){

    /*optional but here i am giving it to show how comparing is working with the inputs
     (printing the comparing values check it output)*/
    
    cout<<"Comparing"<<a<<"and"<<b<<endl; 
    return a>b;
}

//Bubble Sort

/* bool(&cmp)(int a, int b) this is how you pass the function as a parameter or
 you accept a function as a parameter inside any function */
 
void bubble_sort(int a[], int n, bool(&cmp)(int a, int b)){
    for(int itr=1; itr<=n-1; itr++){
        for(int j=0; j<=(n-itr-1); itr++)
        {
            if( cmp(a[j], a[j+1]) ) {
                swap( a[j], a[j+1] );
            }
        }
    }
}

int main(){
    int n, key;
    cin>>n;
    int a[1000];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    bubble_sort(a, n, compare);
    for(int i=0; i<n; i++){
        cout<<a[i]<<",";
    }
    return 0;
}

/* Input:-

5

1  4  5  3  2

OUTPUT:-

Comparing 1 and 4
Comparing 4 and 5
Comparing 5 and 3
Comparing 5 and 2
Comparing 1 and 4
Comparing 4 and 3
Comparing 4 and 2
Comparing 1 and 3
Comparing 3 and 2
Comparing 1 and 2

1 , 2, 3, 4, 5 */