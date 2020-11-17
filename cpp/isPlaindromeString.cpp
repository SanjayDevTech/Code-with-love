/*
Problem statement : Write a function that takes a string and determines whether it's a palindrome or not. The function should return a boolean (true or false value).
Probelm Link : https://edabit.com/challenge/FSeXe93hxXFyJQpzN
*/

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
	string ans="";
	for(int i=0; i<s.length(); i++){
	    if(isalnum(s[i]))
	        ans+=s[i];
	}
	for(int i=0, j=ans.length()-1; i<=j; i++, j--){
	    if(tolower(ans[i])!=tolower(ans[j]))
	        return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	cout << "+----------------------------------------------------------+" << endl;
	cout << "Welcome to check whether the string is palindrome or not" << endl;
	string s;
	cout << "Enter string : ";
	getline(cin,s);
	bool flag = isPalindrome(s);
	if(flag)
		cout<< "It is a palindrome" << endl;
	else
		cout <<"It is not a palindrome" << endl;
	return 0;
}