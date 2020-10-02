#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



int main (){
    char words[200];
    printf ("Enter the word that needs to be checked:\n"); //Asking the user to input the value.
    scanf ("%s", words);

    int l = 0; //Defining the lower index.
    int r = strlen(words) - 1; //Defining the higher index.

    char palindrome[50];
    printf ("%s", words);

    //Comparing the value until the condition is met.
    while (r > l){
        if (words[l++] != words[r--]){//Lower and higher index does not match.
            strcpy (palindrome, " is not a Palindrome");
        }
        else {//Lower and higher index matched.
            strcpy (palindrome, " is a Palindrome");
        }
    }
    printf ("%s", palindrome); //Printing the results.
    return 0;
}