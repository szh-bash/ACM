#include<cstdio>
#include<algorithm>
using namespace std;
const int N=32,inf=~0U>>1;
int v[524300][N],tmp[N],f[N];
int n,m,K,q,op,i,x,y,ans;
inline void set(int x){
  for(int i=0;i<m;i++)scanf("%d",&f[i]);
  for(int S=0;S<=K;S++){
    v[x][S]=0;
    for(int i=0;i<m;i++)if(S>>i&1)v[x][S]+=f[i];else v[x][S]-=f[i];
  }
}
inline void merge(int a[],int b[],int c[]){
  for(int i=0;i<=K;i++)c[i]=max(a[i],b[i]);
}
void build(int x,int a,int b){
  if(a==b){
    set(x);
    return;
  }
  int mid=(a+b)>>1;
  build(x<<1,a,mid);
  build(x<<1|1,mid+1,b);
  merge(v[x<<1],v[x<<1|1],v[x]);
}
void change(int x,int a,int b,int c){
  if(a==b){
    set(x);
    return;
  }
  int mid=(a+b)>>1;
  if(c<=mid)change(x<<1,a,mid,c);
  else change(x<<1|1,mid+1,b,c);
  merge(v[x<<1],v[x<<1|1],v[x]);
}
void ask(int x,int a,int b,int c,int d){
  if(c<=a&&b<=d){
    merge(tmp,v[x],tmp);
    return;
  }
  int mid=(a+b)>>1;
  if(c<=mid)ask(x<<1,a,mid,c,d);
  if(d>mid)ask(x<<1|1,mid+1,b,c,d);
}
int main(){
  scanf("%d%d",&n,&m);
  K=(1<<m)-1;
  build(1,1,n);
  scanf("%d",&q);
  while(q--){
    scanf("%d%d",&op,&x);
    if(op==1)change(1,1,n,x);
    else{
      scanf("%d",&y);
      for(i=0;i<=K;i++)tmp[i]=-inf;
      ask(1,1,n,x,y);
      ans=-inf;
      for(i=0;i<=K;i++)ans=max(ans,tmp[i]+tmp[i^K]);
      printf("%d\n",ans);
    }
  }
}
