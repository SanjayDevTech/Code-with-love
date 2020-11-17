#include<stdio.h>

int a[100];
int i, n;
//void display();
void shellSort();

int main(){
    printf("Enter number of array elements you want to enter : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
        for(i=0; i<n ; i++)
            scanf("%d",&a[i]);
    printf("After Shell Sort : \n");
    shellSort();

}

void shellSort(){
    int flag = 1, gap = n;
    while ( flag==1 || gap>1)
    {
        flag = 0;
        gap = (gap+1)/2;
        for(i=0 ; i<n-gap ; i++)
        {
            if(a[i+gap]>a[i])
            {
                int temp = a[i];
                a[i] = a[i+gap];
                a[i+gap] = temp;
                flag = 0;
            }
        }
    }
    
    for(i = n-1; i>=0; i--)
        printf("%d \t", a[i]);
}