//线段树模拟费用流
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200010,M=530000;
int n,m,i,j,a[N],pa[N],pb[N],v[M],tag[M];ll ans,now;
struct P{int b,c;P(){}P(int _b,int _c){b=_b,c=_c;}}b[N],c[N];
inline bool cmp(const P&a,const P&b){return a.c-a.b<b.c-b.b;}
inline bool cmp2(const P&a,const P&b){return a.b==b.b?a.c<b.c:a.b<b.b;}
void build(int x,int a,int b){
  v[x]=tag[x]=0;
  if(a==b)return;
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
inline void tag1(int x,int p){tag[x]+=p;v[x]+=p;}
inline void pub(int x){if(tag[x])tag1(x<<1,tag[x]),tag1(x<<1|1,tag[x]),tag[x]=0;}
void change(int x,int a,int b,int c,int d,int p){
  if(c<=a&&b<=d){tag1(x,p);return;}
  pub(x);
  int mid=(a+b)>>1;
  if(c<=mid)change(x<<1,a,mid,c,d,p);
  if(d>mid)change(x<<1|1,mid+1,b,c,d,p);
  v[x]=min(v[x<<1],v[x<<1|1]);
}
int ask(int x,int a,int b,int c,int d){
  if(c>d)return 0;
  if(c<=a&&b<=d)return v[x];
  pub(x);
  int mid=(a+b)>>1,t=0;
  if(c<=mid)t=ask(x<<1,a,mid,c,d);
  if(d>mid)t=min(t,ask(x<<1|1,mid+1,b,c,d));
  return t;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(i=1;i<=n;i++)scanf("%d",&a[i]);
  for(i=1;i<=m;i++)scanf("%d%d",&b[i].b,&b[i].c);
  sort(a+1,a+n+1);
  sort(b+1,b+m+1,cmp);
  for(i=1;i<=n;i++)c[i]=P(a[i],-i);
  for(i=1;i<=m;i++)c[i+n]=P(b[i].b,i);
  sort(c+1,c+n+m+1,cmp2);
  for(i=1;i<=n+m;i++)if(c[i].c<0)pa[-c[i].c]=i;else pb[c[i].c]=i;
  build(1,1,n+m);
  for(i=n,j=m;i;i--){
    change(1,1,n+m,pa[i],n+m,-1);
    while(j){
      if(ask(1,1,n+m,pb[j],n+m)>=-1&&ask(1,1,n+m,1,pb[j]-1)>=0){
        now+=a[i]-b[j].b+b[j].c;
        change(1,1,n+m,pb[j],n+m,1);
        ans=max(ans,now);
        j--;
        break;
      }
      j--;
    }
  }
  printf("%lld",ans);
}
