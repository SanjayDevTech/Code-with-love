/* Problem-Statement : Create a function that counts the number of times a particular letter shows up in the word search.
 * Problem Link : https://edabit.com/challenge/bsPZtsX62zQmRHNjX
*/

#include <iostream>
#include <vector>
using namespace std;

int letterCounter(vector<vector<char>> &arr, char c) {
	int count=0;
    for(auto v:arr) {
        for(char ch:v) {
            if(ch==c)
                count++;
        }
    }
    return count;
}

int main() {
    vector<vector<char> > arr(5, vector<char>(6)); // Note - You will always be given an array with five sub-arrays(whose size is 6).

    for(auto &v:arr) {
        for(char &ch:v)
            cin>>ch;
    }

    char c; // The character to be searched.
    cin>>c;

    cout<<letterCounter(arr, c)<<endl;
    return 0;
}