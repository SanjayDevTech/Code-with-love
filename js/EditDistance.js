/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minEditDistance = function(a, b)
{
        var n=a.length;
    var m=b.length;
    if(n==0) return m;
    if(m==0) return n;
    var dp=new Array(n+1);
    for(var i=0;i<=n;i++)
        {
            dp[i]=new Array(m+1);
        }
    
    dp[0][0]=0;
    for(var i=1;i<=n;i++)
        {
            dp[i][0]=i;
        }
    for(var j=1;j<=m;j++)
        {
            dp[0][j]=j;
        }
 
    
    for(var i=1;i<=n;i++)
        {
            for(var j=1;j<=m;j++)
                {
                   if(a[i-1]==b[j-1])
                       {
                           dp[i][j]=dp[i-1][j-1];
                       }
                    else
                        {
                            
                            dp[i][j]=1+Math.min(dp[i][j-1],Math.min(dp[i-1][j],dp[i-1][j-1]));
                        }
                 
                }
        }
    
    return dp[n][m];
};
