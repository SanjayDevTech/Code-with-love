//https://www.interviewbit.com/problems/rotated-sorted-array-search/

int Solution::search(const vector<int> &arr, int b) {

    int n=arr.size() ;
    if(n==0)    return -1 ;

    int s=0,e=n-1 ,p=-1;

    while(s<=e)
    {
        int mid = s+(e-s)/2 ;
        if(arr[mid]==b) return mid ;

        if(mid<e-1 && arr[mid]>arr[mid+1])
        {
            p = mid ;
            break ;
        }
        if(mid>s+1 && arr[mid]<arr[mid-1])
        {
            p = mid-1 ;
            break ;
        }
        if(arr[s]>arr[mid]) e=mid-1 ;
        else    s=mid+1 ;
    }

    if(p==-1)
    {
        s = 0 ;
        e=n-1 ;
    }
    else if(arr[0]<b)
    {
        s = 0 ;
        e = p;
    }
    else{
        s = p+1 ;
        e=n-1 ;
    }

    while(s<=e)
    {
        int mid = s+(e-s)/2 ;
        if(arr[mid]==b) return mid ;

        if(arr[mid]<b)  s=mid+1 ;
        else e = mid-1 ;
    }
    return -1 ;
}
