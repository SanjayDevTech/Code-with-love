//Recursion: Reverse a String
//Problem Statement - Write a function that reverses a string. Make your function recursive.
// Link - https://edabit.com/challenge/HXGx9oXukEgsFK6PH
#include<iostream>
#include<string.h>
using namespace std;
string reverse(string str) {
	if(str.length()<=1)
		return str;
	string smallAns=reverse(str.substr(1,str.length()-1));
	return smallAns+str.at(0);
}
