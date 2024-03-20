#include<iostream>

using namespace std;

class prim
{
public:
    int g[10][10], n, wt;

    void input()
    {
        int i, j;
        char ans;
        cout<<"Enter number of vertices::";         //Here I have considered every vertex is connected to every other vertex
        cin>>n;
        cout<<endl;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                g[i][j]=999;                        //Initially adding max weight to each edge as 999
            }
        }

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(g[j][i]==999 && i!=j)
                {
                    cout<<"Do you want to enter weight at ("<<i<<","<<j<<")? y/n: ";
                    cin>>ans;
                    if(ans=='y' || ans=='Y')
                    {
                        cout<<"\tEnter weight-";
                        cin>>wt;
                        g[i][j]=g[j][i]=wt;
                    }
                }
            }
        }
    }

    void flow()
    {
        int ne,i,j,min,sel[10],x,y,total;
        total=0;

        for(i=0; i<n; i++)
            sel[i]=0;

        sel[0]=1;

        cout<<"\nTree with minimum sum of weights:";
        for(ne=0; ne<n-1; ne++)
        {
            min=999;
            for(i=0; i<n; i++)
            {
                if(sel[i]==1)
                {
                    for(j=0; j<n; j++)
                    {
                        if(sel[j]==0)
                        {
                            if(min>=g[i][j])
                            {
                                min=g[i][j];
                                x=i;
                                y=j;
                            }
                        }
                    }
                }
            }
            sel[y]=1;
            cout<<"\n"<<x<<"->"<<y;                         //Here 'x' is the starting node and 'y' the ending node
            total=total+min;
        }
        cout<<"\n**Total cost= "<<total;
    }
};

int main()
{
    prim o;
    o.input();
    o.flow();

    return 0;
}
