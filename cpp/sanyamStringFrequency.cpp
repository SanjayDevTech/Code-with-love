#include <iostream> 
using namespace std; 
int count(string a, string b, int m, int n) 
{ 
    if ((m == 0 && n == 0) || n == 0) 
        return 1; 
    if (m == 0) 
        return 0; 
    if (a[m - 1] == b[n - 1]) 
        return count(a, b, m - 1, n - 1) + 
               count(a, b, m - 1, n); 
    else
        return count(a, b, m - 1, n); 
} 
int main() 
{ 
    string a = "abcabcadrewabc"; 
    string b = "abc"; 
  
    cout << count(a, b, a.size(), b.size()) << endl; 
  
    return 0; 
} 