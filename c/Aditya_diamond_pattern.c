/* Authored by Aditya Gor 
Program prints a diamond shape based on the number entered by the user */
#include<stdio.h>
#include<conio.h>

void main()
{
    int i,j,n,k,i1,j1,k1;
    printf("enter number\t");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        for (k=1;k<=n-i;k++)
        {
            printf(" ");
        }
        for (j=1;j<=i;j++)
        {
            printf("* ");
        }
        printf("\n");
    }


    for (i1=n-1;i1>=1;i1--)
    {
        for (k1=n-i1;k1>=1;k1--)
        {
            printf(" ");
        }
        for (j1=i1;j1>=1;j1--)
        {
            printf("* ");
        }
        printf("\n");
    }
}

