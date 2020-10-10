#include <stdio.h>                   
#include<string.h>                   
#define max 20                   
void binarysearch(char [][20],int,char[]);    
void main()                  
{
    char string[max][20],t[20],word[20];     
    int i, j, n;
    printf("Enter the number of words: \n");
    scanf("%d", &n);                          
    printf("Enter the words: \n");
    for (i = 0; i < n; i++)            
            scanf("%s",string[i]);
             
    printf("Enter the element to be searched: \n");
   scanf("%s",word); 
    //Linear Search//
    for(i=0;i<10;i++)
    {
    	if(strcmp(string[i],word)==0)
    	   {
    	   	printf("the %s is in %dth position in linear search.\n",word,i+1);
    	   	break;
    	   }
    }
    for (i = 1; i < n; i++)
    {
      for (j = 1; j < n; j++)
      {                                          
          if (strcmp(string[j - 1], string[j]) > 0)
          {                                       
              strcpy(t, string[j - 1]);
               strcpy(string[j - 1], string[j]);
              strcpy(string[j], t);
          }
      }
   }
   printf("Now the inputed words are sorted\n");                 
   binarysearch(string,n,word);                     
}
