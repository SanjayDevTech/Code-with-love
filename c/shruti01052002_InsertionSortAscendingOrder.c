/**
Insertion Sort (Ascending Order)
1. Insertion takes minimum time in sorting if the size of array is small.
2. In Insertion sort every element is compare to it's previous element
   and in Selection Sort every element is compared to  successive  element and in bubble sort every consecutive elements.
**/
#include<stdio.h>
int main()
{
    int n, i, c, j, key;
    printf("Enter the length of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array to be sorted in ascending order :");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);//Taking input of Array Element
    for(i=1;i<n;i++)
    {
        key = arr[i];
        j = i-1;
        while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }

    printf("Array after sorting in ascending order :\n");
    for(i=0;i<n;i++)
    printf("%d ",arr[i]);
    return 0;
}
/**
Output:
Enter the length of array: 7
Enter the elements of array to be sorted in ascending order :
9 7 8 6 5 7 4
Array after sorting in ascending order :
4 5 6 7 7 8 9
Process returned 0 (0x0)   execution time : 30.138 s
Press any key to continue.
**/
