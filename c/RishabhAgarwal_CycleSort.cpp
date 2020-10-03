#include <bits/stdc++.h>
using namespace std;

// cycle sort function
void cycle_sort(int a[], int n){
    int element,small; 
    // i is the pointer and will iterate the array till i=n-2 
    for(int i=0; i<=n-2; i++){  
        element=a[i];
        // small set to i because till i every element will be
        // smaller than a[i] so we can start checking from i+1  
        small=i;  
        for(int j=i+1; j<n; j++){  
            if(a[j]<element){  
                small++;
            }
        } 
        // skip if already set 
        if(small==i){  
            continue; 
        }
        // increasing small in case of repeated numbers 
        while(element==a[small]){ 
            small++; 
        } 
        // again checking whether already set or not 
        // if not we will swap the a[small] and element
        if(small!=i){    
            //temp=element;  
            //element=a[small];  
            //a[small]=temp; 
            swap(a[small],element);     
        }  
        // iterating through till we complete the whole cycle
        while (small!=i){
            // small set to i because till i every element will be
            // smaller than a[i] so we can start checking from i+1  
            small=i;  
            for(int j=i+1; j<n; j++){ 
                if(a[j]<element){  
                    small+=1;
                }
            }
            // increasing small in case of repeated numbers  
            while(element==a[small]){  
                small+=1;
            }  
            // finally swapping if not equal
            if(element!=a[small]){  
                //temp=element;  
                //element=a[small];  
                //a[small]=temp; 
                swap(a[small],element);       
            }  
        }  
    } 
}

// driver function
int main(){
    // input array
    int a[7]={5,2,1,7,1,-1,0};
    // calling cycle sort function
    cycle_sort(a,sizeof(a)/sizeof(a[0]));
    // printitng the sorted array
    cout<<"Array after being sorted: \n";
    for(auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}