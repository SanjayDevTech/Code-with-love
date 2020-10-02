//https://www.interviewbit.com/problems/matrix-search/

int Solution::searchMatrix(vector<vector<int> > &arr, int b) {

    //arr is 2d matrix with n x m dimensions
    int n = arr.size() ;
    int m = arr[0].size() ;

    bool bs = 0 ;
    int row =0 ;

    //matrix is sorted row and column wise

    //variable row is for finding the row where b can be situated
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]<=b && arr[i][m-1]>=b)
        {
            bs = 1 ;
            row = i ;
            break ;
        }
        if(arr[i][0]>b) return 0 ;
    }

    int l = 0,r = m-1 ;

    while(l<=r)
    {
        int mid = l + (r-l)/2 ;

        if(arr[row][mid]==b)    return 1 ;
        else if(arr[row][mid]>b)    r = mid-1 ;
        else    l = mid+1 ;
    }
    return 0 ;
}
