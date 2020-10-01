#include<bits/stdc++.h>
using namespace std;

void camelcase(vector<string>s,int n,char p[]){
	
	int i=0;
	map< string,int>mp;
	while(i<n){
		int count=0;
		int k=0;
		for(int j=0;j<s[i].size();j++){
			if(s[i][j]==p[k]){
				count++;
				k++;
			}
			
		}
		if(count==strlen(p)){
			mp[s[i]]++;
		}
		i++;
	}
		map< string,int> :: iterator it=mp.begin();
		int l=0;
		for(;it!=mp.end();it++){
			if(it->second==1){
				l++;
				cout<<it->first<<" ";
			}
		}
		if(l==0){
			cout<<"No match found"<<endl;
		}
	
}
int main(){
    int test;
    cin>>test;
    while(test--){
        vector<string>s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string t;
		cin>>t;
		s.push_back(t);
	}
	char p[1000];
	cin>>p;
	camelcase(s,n,p);
    }
	
}
