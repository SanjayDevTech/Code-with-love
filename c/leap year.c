// Leap Year Program

#include <stdio.h>
int main()
{
    int year;

    printf("Enter year: ");
    scanf("%d",&year);

    if(year % 4 == 0)
    {
        if( year % 100 == 0)
        {
            if ( year % 400 == 0)
                printf("%d is a Leap Year", year);
            else
                printf("%d is not a Leap Year", year);
        }
        else
            printf("%d is a Leap Year", year );
    }
    else
        printf("%d is not a Leap Year", year);

    return 0;
}

/* Output:
Enter year: 2014
2014 is not a Leap Year
*/
