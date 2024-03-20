/**
Selection Sort
1. Lowest Element takes it's position first.
2. Here Arr[i] is fixed and Compared with all successive element
3. It takes less time than Bubble Sort to execute.
**/
#include<stdio.h>
int main()
{
    int n, i, c, j;
    printf("Enter the length of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    for(i=0;i<(n-1);i++)
    {
        for(j=i+1;j<(n-i);j++)
        {
            if(arr[i]>arr[j])
            {
                c = arr[i];
                arr[i] = arr[j];
                arr[j] = c;
            }
        }
    }
    printf("Elements of array after Sorting in Ascending Order: \n");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}
/**
Output:
Enter the length of array: 7
Enter the elements of array:
9 6 8 3 4 5 7
Elements of array after Sorting in Ascending Order:
3 4 6 9 8 5 7
Process returned 0 (0x0)   execution time : 20.597 s
Press any key to continue.
**/
