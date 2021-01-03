// Bubble sort implementation in C


#include<stdio.h>

int main(){

   int count, temp, i, j, number[30];

   printf("Enter the number of elements... ");
   scanf("%d",&count);

   printf("Enter %d elements: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&number[i]);

  // bubble sort starts
   for(i=count-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Elements in sorted order are...")
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
