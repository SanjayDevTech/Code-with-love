#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int row, col, i, j;
void DF();
void BF();
int main()
{
    printf("Enter rows and columns of adjacency matrix : \n ");
    printf("Row - ");
    scanf("%d",&row);
    printf("Column - ");
    scanf("%d",&col);
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            scanf("%d",&a[i][j]);
    int x;
    char ch ='y';
    while(ch=='y')
    {
        printf("Choose traversal : \n 1.) Breath First Traversal \n 2.) Depth First Traversal \n");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                BF();
                break;
            
            case 2:
                DF();
                break;
                
            default:
                printf("Wrong");
                break;
        }
        printf("Do you want to choose again? y/n \n ");
        scanf(" %c",&ch);
    }
    
}

void BF()
{
    int printed[100]={0};
    int q[100];
    int rear = -1, front = -1;
    int start = 0;
   q[++rear] = start;
    printed[start] = 1;
    while(rear != front)
    {
        start = q[++front];
        printf("%c \t",start + 65);
        for(i= 0; i<row ; i++)
        {
            if(a[start][i] == 1 && printed[i]==0)
            {
                q[++rear] = i;
                printed[i] = 1;
            }
        }
    }
}

void DF()
{
    int st[100], tos = -1;
    int printed1[100] = {0};
    int start = 0;
    printf("%c \t",start + 65);  //
    printed1[start] = 1;
    st[++tos] = start;
    while(tos!=-1)
    {
        start = st[tos];
        for(i=0 ; i< row; i++)
        {
            if(a[start][i] && printed1[i]==0)
                
            {
                st[++tos] = i;
                printf("%c \t ", i + 65);
                printed1[i]= 1;
                break;
            }
        }
        if (i==row)
            tos--;
    }
}
