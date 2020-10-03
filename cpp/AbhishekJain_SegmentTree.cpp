#include<iostream>
#define mid(l,r) ((l+r)/2)
#define lchild(i) (2*i+1)
#define rchild(i) (2*i+2)
using namespace std;

int build(int l,int r,int i,int segment[],int A[]){
    if(l==r)
       return segment[i]=A[l];
    else {
        return segment[i]=build(l,mid(l,r),lchild(i),segment,A)+build(mid(l,r)+1,r,rchild(i),segment,A);
    }

}
int merge(int a,int b)
{
    return (a+b);
}

int query(int ll,int rr,int l,int r,int i,int segment[]){
    if(ll<=l && rr>=r)
        return segment[i];
    if(rr<=mid(l,r))
        return query(ll,rr,l,mid(l,r),lchild(i),segment);
    if(ll>mid(l,r))
        return query(ll,rr,mid(l,r)+1,r,rchild(i),segment);
    else
        return merge(query(ll,rr,l,mid(l,r),lchild(i),segment),query(ll,rr,mid(l,r)+1,r,rchild(i),segment));
}

void update(int pos,int val,int i,int segment[],int l,int r){
    if(l==r)
        segment[i]=val;
    else{
    if(pos<=mid(l,r))
        update(pos,val,lchild(i),segment,l,mid(l,r));
    else if(pos>mid(l,r))
        update(pos,val,rchild(i),segment,mid(l,r)+1,r);
    segment[i]=segment[lchild(i)]+segment[rchild(i)];}
}





int main(){
int n;
cin>>n;
int A[n];
for(int i=0;i<n;i++)
cin>>A[i];

int segment[4*n];
build(0,n-1,0,segment,A);

//for(int i=0;i<13;i++)
 //   cout<<segment[i]<<" "<<endl;
   int q;
   cin>>q;
   while(q--){
    int k,l,r;
    cin>>k>>l>>r;
    if(k==1){
            update(l,r,0,segment,0,n-1);
    }
    else{
    cout<<query(l,r,0,n-1,0,segment)<<endl;
   }
   }



return 0;
}
