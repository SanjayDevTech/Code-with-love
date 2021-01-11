package Sorting;
import java.util.Scanner;
public class Selection {
static Scanner sc=new Scanner(System.in);
    public static void sort(int array[]) {
    	int n=array.length;int min;
    	for(int i=0;i<n-1;i++) {
    		min=i;
    		for(int j=i;j<n;j++)
    			if(array[j]<array[min])
    				min=j;
    		int temp=array[min];
    		array[min]=array[i];
    		array[i]=temp;
    	}
    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		Selection x=new Selection();
		int n=sc.nextInt();
		int array[]=new int[n];
		for(int i=0;i<n;i++)array[i]=sc.nextInt();
		x.sort(array);
		for(int ele: array)System.out.print(ele+" ");
	}

}
