
#include <stdio.h>

int main()
{
    int i, j, c=1, row, col, counter =0;
    int a[10][10], b[26][3];
    
    printf("\n Enter the number of rows and columns : \n");
    scanf("%d %d",&row,&col);
    printf("\n Enter the elements of the array : \n");
    for(i=0 ; i<row ; i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j] == 0)
            {
                counter++; //count number of zeroes
            }
        }
    }
    b[0][0]=row;
    b[0][1]=col;
    b[0][2]=row*col - counter; // non zero elements
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(a[i][j]!=0)
            {
               b[c][0]=i; //row
                b[c][1]=j;  //column
                b[c][2]=a[i][j]; //elements
                c++;
            }
        }
    }
    
    if(counter > ((row*col)/4))
    {
    printf("\n The sparse matrix is given by :\n ");
    for(i=0;i<c;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d \t",b[i][j]);
        }
        printf("\n");
    }
    }
    else
        printf("\n Sparse Matrix is not possible.\n"); // number of 0s should be greater than no of non zero numbers
}
