#include<stdio.h>
void main(){
	int n,b[50],temp;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(b[j]>b[j+1]){
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}
		}
	}
	printf("THE SORTED ARRAY:\n");
	for(int k=0;k<n;k++)
		printf("%d ",b[k]);
	printf("\n");
}