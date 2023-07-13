// find leap year or not using nested if else....

#include <stdio.h>


int main(){
    int year;
    printf("Enter a year to check: ");
    scanf("%d", &year);
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                printf("Leap year");
            }
            else {
                printf("Not a leap year");
            }
        }
        else {
            printf("Leap year");
        }
    }
    else {
        printf("Not a leap year");
    }
    return 0;
}
