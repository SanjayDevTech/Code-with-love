#include<stdio.h>

int a[100];
int i, n;
void display();
void HeapSort();
void heapify(int a[], int n, int i);

int main()
{
    printf("Enter number of array elements you want to enter : ");
    scanf("%d",&n);
    printf("Enter the elements : ");
        for(i=0; i<n ; i++)
            scanf("%d",&a[i]);
    printf("After Heap Sort : \n");
    HeapSort();
    display();

}
void display(){
    for(i=0; i<n ; i++)
        printf("%d \t ",a[i]);
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < n && a[l] > a[largest])
      largest = l;

    if (r < n && a[r] > a[largest])
      largest = r;

    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
    
}


void HeapSort()  //first we make max heap out of entered elements(heapify), then delete first node, put at end, heapify again and repeat these steps until all are deleted.

{
    for (int i = n / 2 - 1; i >= 0; i--)  // internal nodes start from n/2-1
        heapify(a, n, i);
    
    for (int i=n-1; i>=0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i]= temp;
      heapify(a, i, 0);
    }
}
