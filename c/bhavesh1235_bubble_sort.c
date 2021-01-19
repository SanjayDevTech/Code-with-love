/* Implementing Bubble sort in a C Program
 
 */
#include<stdio.h>

int main(){

   int count, temp, i, j, num[30];

   printf("How many numbers are u going to enter: ");
   scanf("%d",&count);

   printf("Enter %d numbers: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&num[i]);

   /* This is the main logic of bubble sort algorithm 
    */
   for(i=count-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(num[j]>num[j+1]){
           temp=num[j];
           num[j]=num[j+1];
           num[j+1]=temp;
        }
      }
   }

   printf("Sorted elements after performing bubble sort are: ");
   for(i=0;i<count;i++)
      printf(" %d",num[i]);

   return 0;
}
