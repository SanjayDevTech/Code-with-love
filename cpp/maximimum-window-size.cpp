#include<bits/stdc++.h>
using namespace std;

void help(int *arr, int n){
    
    stack<int>s;
    int left[n+1];
    int right[n+1];
    
    for(int i=0;i<n;i++){
        left[i]=-1;
        right[i]=n;
    }
    
    for(int i=0;i<n;i++){
        while(!s.empty()&& arr[s.top()]>=arr[i])
            s.pop();
            
        if(!s.empty())
            left[i]=s.top();
        
        s.push(i);
    }
    
    while(!s.empty())
        s.pop();
    
    
    for(int i=n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()]>=arr[i])
            s.pop();
            
        if(!s.empty())
            right[i]=s.top();
            
        s.push(i);
    }
    
    int ans[n+1];
    for(int i=0;i<=n;i++)
        ans[i]=0;
        
    for(int i=0;i<n;i++){
        int len= right[i]-left[i]-1;
        ans[len]= max(ans[len], arr[i]);
    }    
    
    for(int i=n-1;i>=1;i--){
        ans[i]=max(ans[i], ans[i+1]);
    }
    
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    
}


int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        help(arr,n);
        cout<<endl;
    
    }
    
    return 0;
}