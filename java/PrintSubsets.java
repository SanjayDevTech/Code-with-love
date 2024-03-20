package com.company;

public class PrintSubsets
{
    static void printArray(int sub[])
    {
        for(int i=0;i<sub.length;i++)
        {
            if(sub[i]!=0)
                System.out.print(sub[i]+",");
        }
        if(sub[0]==0)
            System.out.println("Printing 0");
        else
            System.out.println();
    }

    static int[] add(int sub[],int ele)
    {
        for(int i=0;i<sub.length;i++)
            if(sub[i]==0)
            {
                sub[i]=ele;
                break;
            }
        return sub;
    }

    static void removeElement(int sub[])
    {
        int i;
        for(i=0;i<sub.length;i++)
        {
            if(sub[i]==0) {
                if (i - 1 != -1)
                    sub[i - 1] = 0;
                break;
            }
        }

        if(i==sub.length)
            sub[i-1]=0;
    }

    static void subsets(int arr[],int index, int sub[])
    {
        if(index==arr.length)
        {
            printArray(sub);
            return;
        }

        subsets(arr,index+1 , add(sub,arr[index]));
        removeElement(sub);
        subsets(arr,index+1 , sub);
    }
public static void main(String[] args)
    {
        int arr[]={1,2,3};
        int index=0;
        int sub[]=new int[3];


        subsets(arr,index,sub);

    }
}
