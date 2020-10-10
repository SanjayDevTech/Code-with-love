#include <stdio.h>

int search(int array[], int n, int x) {
  
  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] != x)
      continue;
    return i;
  return -1;
}

int main() {
  int array[] = {2, 4, 0, 1, 9, 10, 87,42};
  int x = 1;
  int n = sizeof(array) / sizeof(array[0]);

  int result = search(array, n, x);

  if(result == -1 )
    printf("Element not found") 
  else 
    printf("Element found at index: %d", result);
}
