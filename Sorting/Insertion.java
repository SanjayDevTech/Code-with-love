package Sorting;

import java.util.Scanner;

public class Insertion {
	static Scanner sc=new Scanner(System.in);
	public static void sort(int [] array) {
		int n=array.length,j;
		for(int i=1;i<n;i++) {
			int temp=array[i];
			for(j=i-1;j>=0 && temp<array[j];--j) {
				array[j+1]=array[j];
			}
			array[j+1]=temp;
		}
	}
	public static void main(String[] args) {
		int n=sc.nextInt();
		int A[]=new int[n];
		for(int i=0;i<n;i++)A[i]=sc.nextInt();
		sort(A);
		for(int x:A)System.out.print(x+" ");
	}
}
