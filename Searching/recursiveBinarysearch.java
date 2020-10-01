package Searching;
import Sorting.Selection;
import java.util.Scanner;

public class recursiveBinarysearch {
static Scanner sc=new Scanner(System.in);
	    public static int search(int array[],int key,int li,int ui) {
		int curindex=(li+ui)/2;
		if(li>ui)return -1;
		if(array[curindex]==key)return key;
		else if(key>array[curindex])return search(array,key,curindex+1,ui);
		else 
			return search(array,key,li,curindex-1); 
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=sc.nextInt();
		int array[]=new int[n];
		for(int i=0;i<n;i++)
			array[i]=sc.nextInt();
		Selection.sort(array);
		int key=sc.nextInt();
		int x=search(array,key,0,n-1);
		if(x==key)System.out.println("Yes");
		if(x==-1)
			System.out.println("no");
		}

}
