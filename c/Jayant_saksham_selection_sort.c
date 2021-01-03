#include <stdio.h>
int main()
{
  int A[10], n, i, j, min, swap;
  printf("Enter number of elements\n");
  scanf("%d", &n);
  printf("Enter %d integers\n", n);
  for (i=0;i<n;i++){
    scanf("%d", &A[i]);
  }
  for (i=0;i<(n-1);i++) 
  {
    min = i;
    for(j=i+1;j<n;j++)
    {
      if (A[min]>A[j])
        min = j;
    }
    if (min!=i)
    {
      swap = A[i];
      A[i] = A[min];
      A[min] = swap;
    }
  }
  printf("Sorted list in asiending order:\n");
  for (i = 0; i < n; i++)
    printf("%d\n", A[i]);

  return 0;
}

//COncept of finding the minimum element from an array
//see Arrays->min_element.c