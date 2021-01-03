#include <iostream>
#include <string.h>
using namespace std;
const char keypad[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno",
"pqrs", "tuv", "wxyz"};
void printWords(int number[], int curr_digit, char output[], int n){
   int i;
   if (curr_digit == n){
      cout<<output<<" ";
      return ;
   }
   for (i=0; i<strlen(keypad[number[curr_digit]]); i++){
      output[curr_digit] = keypad[number[curr_digit]][i];
      printWords(number, curr_digit+1, output, n);
      if (number[curr_digit] == 0 || number[curr_digit] == 1)
         return;
   }
}
int main(){
    int n;
    cin>>n;
   int number[20];
   for(int i=0;i<n;i++)
   {cin>>number[i];}
   cout<<"The output character formed is : \n";
  
   char result[n+1];
   result[n] ='\0';
   printWords(number, 0, result, n);
   return 0;
}
