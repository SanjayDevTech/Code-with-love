//Program to search the continuous pattern in the given string.
//Author: naveen81

#include <iostream>
#include <string>
using namespace std;

/*
Input: string, pattern
Output: bool value
*/
bool FindPattern(string str, string pattern)
{
    int strSize = str.size();
	int patternSize = pattern.size();
	int start = 0, end = patternSize-1;
	bool flag = false;

	while (end<strSize) {
	    if (start + patternSize <= strSize) {
	        string tempStr = str.substr(start, patternSize);
	        if(tempStr == pattern) {
	            flag = true;
	        }
	    }
	    start++;
	    end++;
	}

	return flag;
}

int main() {
	string str, pattern;
	cin>>str>>pattern;

	if (FindPattern(str, pattern)) {
	    cout<<"Pattrn found in string!\n";
	} else {
	    cout<<"Pattern not found in the given string.\n";
	}
	return 0;
}