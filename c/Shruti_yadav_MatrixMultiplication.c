/** Matrix Multiplication **/
#include<stdio.h>
int main()
{
    int i, j, k, m, n, p, q;
    printf("Enter the dimension of matrix A");
    //Taking Input dimension of Matrix A from User
    scanf("%d%d",&m,&n);                        
    int arrA[m][n];
    printf("Enter the elements of matrix A");
    //Taking Input elements of Matrix A from User
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&arrA[i][j]);
        }
    }
    printf("Enter the dimension of matrix B");

    //Taking Input dimension of Matrix B from User
    scanf("%d%d",&p,&q);
    int arrB[p][q];
    printf("Enter the elements of matrix B");

    //Taking Input elements of Matrix B from User
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&arrB[i][j]);
        }
    }
    int arrC[m][q];

    /**
    If the No. of Column of Matrix A is equal to the No. of Rows of Matrix B 
    then we further proceed to the Multiplication
    **/
    if(n==p)
    {

        //Multiplication of Two Matrix A and B assigning it to a new matrix C
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
                arrC[i][j] = 0;
                for(k=0;k<n;k++)
                arrC[i][j] = arrC[i][j]+(arrA[i][k]*arrA[k][j]);  
            }
        }

        //Printing the Matrix C containing the Multiplication of Matrix A and B
        for(i=0;i<m;i++)
        {
            for(j=0;j<q;j++)
            {
             printf("%d ",arrC[i][j]);
            }
            printf("\n");
        }
    }

    /**
    If the No. of Column of Matrix A is not equal to the No. of Rows of Matrix B 
    then the Multiplication is not Possible.
    **/
    else
    {
        printf("Matrix Multiplication is not possible");
    }
    return 0;
}

/**
Output:
Enter the dimension of matrix A2 2
Enter the elements of matrix A
1 2
3 4
Enter the dimension of matrix B2 2
Enter the elements of matrix B
1 2
3 4
7 10
15 22

Process returned 0 (0x0)   execution time : 24.026 s
Press any key to continue.
**/
