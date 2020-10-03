#include<stdio.h>
int main()
{
    int a[100][100],t[100][100], i,j,r,c;
    printf("\nEnter no of rows and columns\n");
    scanf("%d\n%d",&r,&c);

    printf("\nEnter diagonal elements\n") ;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nThe matrix is \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
    {
       printf("%d\t",a[i][j]);
         if(j==r-1)
       printf("\n");
    }
    }
       printf("\nThe transpose matrix is \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
    {
       printf("%d\t",a[j][i]);
       if(j==r-1)
       printf("\n");
    }
    }
return 0;
}