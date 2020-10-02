#include <bits/stdc++.h> 
using namespace std; 

void count(char *, string);

int main() 
{ 
    string repeatedword = "abhishek"; 
    char para[] = "My name is abhishek and my brother's name is abhishek too. The reason my name is abhishek is because the string abhishek is going to be counted in this program"; 
    count(para, repeatedword); 
    return 0; 
} 

void count(char *para, string repeatedword) { 
    char *temp; 
    vector<string> list; 
    temp = strtok(para, " "); 
    while (temp != NULL) { 
        list.push_back(temp); 
        temp = strtok(NULL, " "); 
    } 
    int count_of_word = 0; 
    for (int i = 0; i < list.size(); i++) { 
        if (repeatedword == list[i]) 
            count_of_word++; 
    }
    cout << count_of_word; 
}