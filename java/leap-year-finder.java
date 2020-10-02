//This program is coded by Harshit Sharma( :harshithq )

//This program helps you to find if a give year is a leap year or not

import java.util.*;
import java.io.*;

public class Main {
  public static void main(String args[]) throws IOException 
  {
 Scanner sc=new Scanner(System.in);
 int t=sc.nextInt();       //First Input to check how many time you want to run program
 while(t-->0)
 {
   int n=sc.nextInt();
   if(n%100==0)
   {
     if(n%400==0)
     System.out.println("Yes");
   else
   System.out.println("No");
   continue;
   }
   if(n%4==0)
   System.out.println("Yes");
   else
   System.out.println("No");
 }
  }
}
// Print Yes if it is a leap year and no if it is not.
