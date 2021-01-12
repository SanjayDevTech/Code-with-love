#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 

/* function to check whether two strings are anagram of each other */
bool areAnagram(string str1, string str2) 
{ 
	// Create two count arrays and initialize all values as 0 
	int count[NO_OF_CHARS] = {0}; 
	int i; 

	// For each character in input strings, increment count in 
	// the corresponding count array 
	for (i = 0; str1[i] && str2[i]; i++) 
	{ 
		count[str1[i]]++; 
		count[str2[i]]--; 
	} 

	// If both strings are of different length. Removing this condition 
	// will make the program fail for strings like "aaca" and "aca" 
	if (str1[i] || str2[i]) 
	return false; 

	// See if there is any non-zero value in count array 
	for (i = 0; i < NO_OF_CHARS; i++) 
		if (count[i]) 
			return false; 
	return true; 
} 

// This function prints all anagram pairs in a given array of strigns 
void findAllAnagrams(string arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		for (int j = i+1; j < n; j++) 
			if (areAnagram(arr[i], arr[j])) 
				cout << arr[i] << " is anagram of " << arr[j] << endl; 
} 


/* Driver program to test to pront printDups*/
int main() 
{ 
	string arr[] = {"geeksquiz", "geeksforgeeks", "abcd", 
					"forgeeksgeeks", "zuiqkeegs"}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	findAllAnagrams(arr, n); 
	return 0; 
} 
