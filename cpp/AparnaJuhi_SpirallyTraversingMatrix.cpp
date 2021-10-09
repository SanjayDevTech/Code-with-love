class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>&a) {
        int strow=0;
        int stcol=0,i,j,k;
        int enrow=a.size()-1;
        int encol=a[0].size()-1;
        vector<int>ans;
        while(strow<=enrow && stcol<=encol)
        {
            
            for(j=stcol;j<=encol;j++)
                ans.push_back(a[strow][j]);
            strow++;
            for(k=strow;k<=enrow;k++)
                ans.push_back(a[k][encol]);
            encol--;
            if(strow<=enrow)
            for(k=encol;k>=stcol;k--)
                ans.push_back(a[enrow][k]);
            enrow--;
            if(stcol<=encol)
            for(k=enrow;k>=strow;k--)
                ans.push_back(a[k][stcol]);
            stcol++;
        }return ans;
        
    }
};
