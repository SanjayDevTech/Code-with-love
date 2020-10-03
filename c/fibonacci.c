#include<stdio.h>

int main()
{
    int prev=0,curr=1;
    int next;
    int n; //nth value in fibonacci series
    printf("enter the value of n: ");
    scanf("%d",&n);

    printf("The Fibonacci Series : ")
    printf("%d %d ",prev,curr);
    
    int i;
    for(i=2; i<=n; i++)
    {
        next = curr + prev;
        printf("%d ",next);
        prev = curr;
        curr = next;
    }
    printf("\n");

    return 0;
}