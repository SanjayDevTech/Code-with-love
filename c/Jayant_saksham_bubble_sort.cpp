#include <stdio.h>
int main()
{
    int n, A[100], swap;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Now enter the array elements : ");
    for(int i=0;i<n;i++)     
    scanf("%d", &A[i]);
    for(int i=0;i<(n-1);i++){                 //This line is for number of rounds (the result of first pass is the largest element get sorted)
        for(int j=0;j<(n-i-1);j++){           //This line is for compairing the two adjecent numbers
            if(A[j]>A[j+1]){
                swap=A[j];
                A[j]=A[j+1];
                A[j+1]=swap;
            }
        }
    }
    printf("The sort array using Bubble sort is ");
    for(int i=0;i<n;i++){
        printf("%d ", A[i]);
    }
}

//the concept is ek ek karke maximum number element will get sort
 // f(n)=O(n2)
 // no's on comparisions for n element array = 1+2+3+4+5+.....(n-1)
 // no of swaps = 1+2+3+4+.....(n-1) 
 // the analogy is bubble in water when stone is thrown in water
 