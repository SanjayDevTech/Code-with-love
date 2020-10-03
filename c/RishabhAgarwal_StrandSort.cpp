#include<bits/stdc++.h>
using namespace std;
vector<int>b; // output vector

//merge vector c into output vector
void merge( vector<int>&c ){
    vector<int>d;
    d=b;
    b.clear();
    int i = 0, j = 0;  
    while (i<c.size() && j <d.size()) 
    { 
        if (c[i]<d[j]){ 
            b.push_back(c[i]);
            i++;
        } 
        else{
            b.push_back(d[j]);
            j++; 
        }
    } 
    while (i<c.size()){
        b.push_back(c[i]);
        i++;
    }
    while (j<d.size()){ 
        b.push_back(d[j]);
        j++; 
    } 
}

//strand sort function
void strand_sort( int n, int a[] ){
    int flag[n]; //used to mark that this element is in the output vector(1) or not(0)
    memset(flag,0,sizeof(flag)); //sets initially none of the element is in output vector
    int k=n; //used to store how many elements are left in input array
    vector<int>c; //temporary vector used to store sorted sequences from input array
    //this while loop step by step inserts all sorted sequences from
    //input array to output vector
    while(k>0){
        int h=0;
        for(int x=0; x<n; x++){
            if(flag[x]==0&&a[x]>=h){
                k--;
                flag[x]=1;
                c.push_back(a[x]);
                h=a[x];
            }
        }
        merge(c); //used to merge the small sorted sequences into output vector
        c.clear();
    }
}

//driver function
int main()
{
    int n;  //size of the input array
    cin>>n;
    int a[n];  //input array
    for(int x=0; x<n; x++){
        cin>>a[x];
    }
    strand_sort(n,a); //Here we calls the strand sort function
    for(int x=0; x<n; x++){
        cout<<b[x]<<" ";    //output of the final sorted array
    }
    cout<<"\n";
    return 0;
}