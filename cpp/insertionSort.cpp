#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int a[10], i, j, temp, minIndex, n;
	cout<<"Enter the Array Size :: ";
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
		minIndex = i;
		for(j=i+1; j<n; j++)
		{
			if(a[minIndex]>a[j])
				minIndex = j;
		}
		temp = a[i];
		a[i] = a[minIndex];
		a[minIndex] = temp;
	}
	cout<<endl<<"Sorted Array is :: ";
	for(i=0; i<n; i++)
		cout<<a[i]<<" ";
}
