#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
 
void input_string(vector<char>& str)
{
    char a;
    while (1)
    {
        a = getchar();
        if (a == '\n')
        break;
        str.push_back(a);
    }
    return;
}
 
void print_string(vector<char> strn)
{
    for (std::vector<char>::iterator it = strn.begin();it != strn.end();++it)
    {
        cout<<*it;
    }
    return;
}
 
int match_string(vector<char>& original, vector<char> match)
{
    vector<char>::iterator p,q, r;
    int i = 0;
 
    p = original. begin();
    while (r <= match.end() && p <= original.end())
    {
        r = match.begin();
        while (*p != *r && p < original.end())
        {
            p++;
            i++;
        }
 
        q = p;
        while (*p == *r && r <= match.end() && p<=original.end())
        {
            p++; i++;
            r++;
        }
 
        if (r >= match.end())
        {
            original.erase(original.begin(), q + 1);
            return (i - match.size() + 1);
        }
 
        if (p >= original.end())
        return 0;
        p = ++q;
    }
}
 
 
int main()
{
    std::vector<char> original,match;
    int i,result,k=0,sum=0;
 
    cout<<"Enter String:";
    input_string(original);
    cout<<"Enter Search Pattern:";
    input_string(match);
 
    if (match.size() > original.size())
    {
        cout<<"Error:Original string too small.";
    }
 
    do
    {
        result = match_string(original, match);
        sum += result;    //to store previous found position
        if (result > 0)
        {
            k++;
            cout<<"\nMatch found from Position = "<<sum;
        }
     } while (result > 0);   //loop to find all patterns
 
     if (k == 0)
         cout<<"Error:Match Not Found";
     
     cout<<endl;
     return 0;
}