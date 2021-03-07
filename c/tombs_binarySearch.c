/*
* Returns the position of element in a vector of integers, or -1 if it can't be found
*
*/
int binarySearch(int v[], int left, int right, int x) 
{ 
        int mid = l + (right - l) / 2; 
  
        if (v[mid] == x) 
            return mid; 
  
        if (v[mid] > x) 
            return binarySearch(v, left, mid - 1, x); 
  
        return binarySearch(v, mid + 1, right, x); 
    }  
    return -1; 
} 