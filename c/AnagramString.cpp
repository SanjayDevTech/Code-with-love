#include<bits/stdc++.h>
using namespace std;
string checkAnag(string str1,string str2)
{
    if(str1.length()==str2.length())
    {
        int len = str1.size();
        sort(str1.begin(),str1.end());
        sort(str2.begin(),str2.end());
        for(int i=0;i<len;i++)
        {
            if(str1[i]!=str2[i])
                return"NO";
        }
        return "YES";
    }
    else
    {
        return "NO";
    }

}
int main()
 {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	   string str1,str2;
	   cin>>str1;
	   cin>>str2;
	   cout<<endl<<checkAnag(str1,str2);
	}
	return 0;
}
