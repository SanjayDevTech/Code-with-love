class Solution {
public:
    int trap(vector<int>& a) {
        
        int n=a.size();
          int x=0,j=0,c=0,lmax=0,rmax=n-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>a[rmax])rmax=i;
        }
        for(int i=0; i<n;i++)
        {
            if(a[i]>a[lmax])lmax=i;
            if(i>rmax)
            {
                rmax=i;
                for(int j=i; j<=n-1;j++)
                {
                    if(a[j]>a[rmax])rmax=j;
                }
            }
            int mn=min(a[lmax],a[rmax]);
            c+=mn-a[i];
            cout<<c<<" ";
        }
        return c;
    
    }
};