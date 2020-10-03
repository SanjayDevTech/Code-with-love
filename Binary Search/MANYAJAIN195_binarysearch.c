// C program to implement Binary Search 
#include <stdio.h>
// A binary search function. It returns location of the number in the array
int main()
{
  int i, low, high, mid, n, key, array[100];
  printf("Enter number of elements :");
  scanf("%d",&n);
  printf("Enter %d integers\n", n);
  for(i = 0; i < n; i++)
    scanf("%d",&array[i]);
    printf("Enter value to find :");
    scanf("%d", &key);
  low = 0;
  high = n - 1;
  mid = (low+high)/2;
  while (low <= high) {
  // If element is greater than mid, then it can only be present in right subarray 
    if(array[mid] < key)
    low = mid + 1;
  // If the element is present at the middle itself
  else if (array[mid] == key) {
    printf("%d found at location %d\n", key, mid+1);
    break;}
  // Else the element can only be present in right subarray 
  else
    high = mid - 1;
    mid = (low + high)/2;}
  //when element is not present in array 
  if(low > high)
  printf("Not found! %d isn't present in the list\n", key);
  return 0;
}
