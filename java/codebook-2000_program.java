 import java.util.*;
 import java.lang.*;
 import java.io.*;


class Codechef
{
   static void pattern(int n)
   {
       for(int i=1;i<=n;i++)
       {
           for(int j=i;j<=n;j++)
           System.out.print("*");
           System.out.println();
       }
   }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
		//Enter size of pattern
		int n=Integer.parseInt(buf.readLine());
	   
	   pattern(n);	

	}
}
