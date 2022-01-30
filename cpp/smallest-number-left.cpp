#include<bits/stdc++.h>
using namespace std;

void smallerleft(int array[], int n){
    
    stack<int> s;
    
    for(int i =0;i<n;i++){
        
        while(!s.empty() && s.top() >= array[i]){
            s.pop();
        }
        
        if(s.empty()) cout<<"-1"<<" ";
        else cout<<s.top()<<" ";
        
        
        s.push(array[i]);
    }
    
    cout<<endl;
}

int main()
 {
    int t; cin>>t;
    
    while(t--){
        
        int n; cin>>n;
        
        int array[100000];
        
        for(int i =0;i<n;i++){
            cin>>array[i];
        }
        
        smallerleft(array, n);
    }
	return 0;
}