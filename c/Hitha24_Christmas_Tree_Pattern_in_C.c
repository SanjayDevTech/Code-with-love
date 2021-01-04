#include<stdio.h>
int main()
{
    int n;

    printf("Hey !! Merry christmas\nNow Enter a number for more surprise\n ");
    scanf("%d", &n);
   
    int i,j;
     for(i=1; i<=n; i++)
    {
        for(j=1;j<=n-i; j++)
        {
            printf(" ");
        }
        for(j=1; j<=2*i-1; j++)
        {
            printf("*");
	    }
		printf("\n");	
	}
    for(i=1; i<=n/2; i++)	
    {
        for(j=1; j<=n-2; j++)
        {
            printf(" ");
        }
        printf("|||\n");
    }

    return 0;
}

