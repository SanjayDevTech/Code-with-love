#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int a[10], i, minIndex, temp, n, j;
	cout<<"Enter the Size :: ";
	cin>>n;
	cout<<"Enter the Array Elements :: "<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"The "<<i<<" element is :: ";
		cin>>a[i];
	}
	cout<<"Unsorted Array is :: ";
	for(i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	for(i=0; i<n-1; i++)	
	{
		minIndex = i;		//stores the current index
		for(j=i+1; j<n; j++)
		{
			if(a[minIndex]>a[j])		//comparing to find the smallest element
				minIndex = j;
		}
		temp = a[minIndex];			//swapping the elements
		a[minIndex] = a[i];
		a[i] = temp;
	}
	cout<<endl<<"Sorted Array is :: ";
	for(i=0; i<n; i++)
		cout<<a[i]<<" ";
}
