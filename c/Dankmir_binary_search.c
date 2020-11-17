int BinarySearch(int arr[], int e, int min, int max)
{
    if (max >= min)
    {
        int mid = (min + max) / 2;
        
        if (arr[mid] > e)
        {
            return BinarySearch(arr, e, min, mid-1);
        }
        else if (arr[mid] < e)
        {
            return BinarySearch(arr, e, mid+1, max);
        }
        else
        {
            return mid;
        }
    }
    return -1;
}