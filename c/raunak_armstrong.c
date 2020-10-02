#include<stdio.h>
#include<math.h>

void arm(int a,int b)
{
    int t;
    for(int i=a;i<=b;i++)
    {
        int d=0,sum=0,dig;

        t=i;
        while(t>0)
        {
            t/=10;
            d++;
        }
        t=i;
        while(t>0)
        {
            dig=t%10;
            sum+=pow(dig,d);
            t/=10;
        }
        if(sum==i)
            printf("%d IS ARMSTRONG.\n",i);

    }
}

int main()
{
    int n1,n2;
    printf("ENTER THE RANGE : ");
    scanf("%d%d",&n1,&n2);
    arm(n1,n2);
    return 0;
}

