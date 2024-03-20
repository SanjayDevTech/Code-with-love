package Searching;
import java.util.Arrays;
import java.util.Scanner;
public class BinarySearch {
static Scanner sc=new Scanner(System.in); 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=sc.nextInt();//size of array
		int array[]=new int[n];//array declaration
		for(int i=0;i<n;i++)array[i]=sc.nextInt();
		Arrays.sort(array);
		int search=sc.nextInt();
		int ui=n-1;
		int li=0;
		boolean found=false;
		while(true) {
			int curin=(ui+li)/2;
			if(search==array[curin]) {
				found=true;
				break;
			}
			else if(li>ui)break;
			else if(search>array[curin])
				li=curin+1;
			else
				ui=curin-1;
		}
		if(found)System.out.println("Yes");
		else
			System.out.println("No");
	}

}
