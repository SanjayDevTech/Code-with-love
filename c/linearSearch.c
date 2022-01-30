#include<stdio.h>
int linearSearch(int arr[],int val,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==val)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int size,n;
    int found;
    int arr[]={5,74,2,3,6,1,4,33,22,54,21,12,15};
    printf("Enter the number You want to search in array: ");
    scanf("%d",&n);
    size = sizeof(arr)/sizeof(int);
    found =linearSearch(arr,n,size);
    if(found)
        printf("\npresent");
    else
        printf("\nNot present");
}
