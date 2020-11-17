#include<stdio.h>
int main(){
 long long int a,n,t,i,j,c=1,r,b;
 scanf("%lld",&t);
 while(t--){
  long int ar[2000]={0},br[2000]={0},u=0;
  scanf("%lld %lld",&n,&r);
  while(r--){
   scanf("%lld %lld",&a,&b);
   ar[a]++;
   br[b]++;
  }
  for(i=0;i<n;i++){
   if(ar[i]>0 && br[i]>0){
    u=1;
    break;
   }
  }
  if(u==1){
   printf("Scenario #%lld: spied\n",c);
   c++;
  }else{
   printf("Scenario #%lld: spying\n",c);
   c++;
  }
 }
 return 0;
}
