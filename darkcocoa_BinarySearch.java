  import java.io.*;
  class BinarySearch
  {
      public void main()throws IOException
      {
          BufferedReader r=new BufferedReader(new InputStreamReader(System.in)); 
          System.out.println("Enter a number. Enter -1 if done.");
          int[] arr=new int[1000];
          int i=0;
          do{
              int x=Integer.parseInt(r.readLine());
              if(x==-1)
              break;
              arr[i]=x;
              i++;
              System.out.println("Enter a number. Enter -1 if done.");
            }while(i<1000);
          arr=sort(arr,i);
          System.out.println("Enter a number to be searched");
          int k=Integer.parseInt(r.readLine());
          search(k,arr,i);
       }
      public int[] sort(int a[],int n)
      {
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<n;j++)
              {
                  if(a[i]<a[j])
                  {
                      int tmp=a[i];
                      a[i]=a[j];
                      a[j]=tmp;
                    }
                }
            }
            System.out.println("the list is");
           for(int y=0;y<n;y++)
                System.out.print(a[y]);
            return a;
        }
       public void search(int k, int a[], int n)
       {
           int l=0, u=n-1, m,pos=-1; boolean fg=false;
           while(l<=u)
           {
               m=(l+u)/2;
               pos=m;
               if(a[m]==k)
               {
                   fg=true; 
                   break;
                }
               if(a[m]>k)
                u=m-1;
               else
                l=m+1;
            }
            if(fg==true)
            System.out.println("key found at position "+pos);
            else
            System.out.println("key not found but can be inserted at "+pos);
        }
    }
            
               
        
           
              