#include <bits/stdc++.h>
using namespace std;

int main() {
	
	
	long long t;
	cin>>t;
	while(t--){
	    
	    long long n;
	    cin>>n;
	    vector<long long> v(n);
	    for(long long i=0;i<n;i++){
	        cin>>v[i];
	    }
	    
	    vector<long long> ans(n);
	    stack<long long> s;
	    
	   
	    s.push(0);
	    
	    long long cur;
	    
	    for(long long i=1;i<n;i++){
	        
	        cur=v[i];
	        
	        
	        while(!s.empty() && cur>v[s.top()]){
	            
	         
	            ans[s.top()]=cur;
	           
	            s.pop();
	            
	        }
	       
	        s.push(i);
	        
	    }
	    
	    
	    while(!s.empty()){
	        
	        ans[s.top()]=-1;
	        s.pop();
	    }
	    
	    for(long long i=0;i<n;i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}