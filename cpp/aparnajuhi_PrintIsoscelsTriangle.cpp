/* Inverted triangle of stars problem - asked in Adobe Interview 
-----The first line of the input contains an integer T denoting the
 number of test cases. Then T test cases follow. Each test case consists
  of a single line containing an integer N denoting the height of the
   inverted isosceles triangle.--------
   
Problem Description :

Input:
2
4
3

Output:
******* *****   ***     *   
***** ***   * 

 
Explanation of Testcase 1:

*******
 *****
  ***  
   *   

*/
#include<bits/stdc++.h>
using namespace std;
int main() 
{
 /* t is number of times the whole program will rum */
	int t;
	cin>>t;
	while(t--)
	{
		/* n denotes the height of inverted isoscels triangle */
	    int n,k;
		cin>>n;
		/* Calculate the number of stars in base . Let say if height is 2, then pattern is :
		***
		 *
		 
		Number of stars in base is 2*height-1
		
		*/
	    int base=2*n-1;
	    int spaces=1;
	    /* The spacing between two different layers of triangle increases by 2, eg: In case of height 3.
		Output: ***** ***   *
		
		Between these 5 continous stars and 3 continuous stars the spacing is of 1.
		 Between the 3 continuous stars and 1 start the spacing is of 1+2=3.
		*/
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<base;j++)
	        cout<<"*";
	        for(k=0;k<spaces;k++)
	        cout<<" ";
	        spaces+=2;
	        base-=2;
	    }
	    cout<<"\n";
	}
	return 0;
}
