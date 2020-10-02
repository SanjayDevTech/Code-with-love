#include<bits/stdc++.h>
using namespace std;
bool anagram(char s[],char t[]){
	if(strlen(s)!=strlen(t)){
		return false;
	}
	int n=strlen(s);
	sort(s,s+n);
	sort(t,t+n);
	if(strcmp(s,t)==0){
		return true;
	}
	else return false;
}
int main(){
	char s[100];
	char t[100];
	cin>>s>>t;
	cout<<anagram(s,t);
}
