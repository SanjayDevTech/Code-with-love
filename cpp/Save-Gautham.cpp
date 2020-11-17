#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t; cin>>t;
	
	while(t--){
	
	stack<int> s;
	
    int n;
    cin>>n;
    
    int a[n];
    
    for(int i=0;i<n;i++) { cin>>a[i];
    }
    
    s.push(a[n-1]);
    
    int c[n];
    
    int k=0;
    
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() && s.top()<=a[i])
        {
            s.pop();
        }
    
        if(s.empty()){
            
            c[k++]=0;
        }else{
            
            c[k++]=s.top();
        }
        
        s.push(a[i]);
    }
    
    int sum=0;
    
    for(int i=k-1;i>=0;i--){
        
        // cout<<c[i]<<" ";
        sum+=c[i]; 
    }
    
    cout<<sum<<endl;
	    
	}
	return 0;
}