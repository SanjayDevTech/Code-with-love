#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Agung-Krisna, 2020
int main(){
    char first[500];
    char second[500];
    int w1;
    int w2;
    printf ("Enter the first word here\n");//Prompting the user to input a string.
    scanf ("%s", first);

    printf ("Enter the second word here\n");//Prompting the user to input another string to check.
    scanf ("%s", second);

    w1 = strlen (first);
    w2 = strlen (second);

    if (w1 != w2){ //checking inequalities.
        printf ("%s and %s is not an Anagram", first, second);
    }
    else { //string is equal.
        printf ("%s and %s is an Anagram", first, second);
    }
}