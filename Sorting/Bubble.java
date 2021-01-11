package Sorting;
import java.util.Scanner;
public class Bubble {
static Scanner sc=new Scanner(System.in);
	void sort(int array[]) {
		int n=array.length;
		for(int i=n-1;i>1;i--) {
			for(int j=0;j<i;j++) {
				if(array[j]>array[j+1]) {
					int temp=array[j];
					array[j]=array[j+1];
					array[j+1]=temp;
				}
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n=sc.nextInt();
		int[] array=new int[n];
		for(int i=0;i<n;i++)array[i]=sc.nextInt();
		Bubble x=new Bubble();
		x.sort(array);
		for(int element:array)System.out.print(element+" ");
	}

}
