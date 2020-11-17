#include<bits/stdc++.h>
using namespace std;

void leaf(vector<int> &v, int n){
    
    stack<int> s;
    
    for(int i =0, j=1; j<n;j++, i++){
        
        bool found = false;
        
        if(v[i] > v[j]) {
            s.push(v[i]);
        }else{
            
            while(!s.empty()){
                if(v[j] > s.top()){
                    s.pop();
                    found = true;
                }else{
                    break;
                }
            }
            
        }
        
        if(found) {
            cout<<v[i]<<" ";
        }
    }
    
    cout<<v[n-1]<<" "<<endl;
}

int main()
 {
	int t; cin>>t;
	
	while(t--){
	    
	    int n; cin>>n;
	    
	    vector<int> v(n);
	    
	    for(int i = 0;i<n;i++){
	        cin>>v[i];
	    }
	    
	    leaf(v,n);
	}
	return 0;
}