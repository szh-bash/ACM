#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define LL long long
#define md(x) ((x)%1000000007)
const int fin=1,maxn=100010;
int tot,root;
int org[maxn];
LL pwr[maxn];
int s[maxn],l[maxn],r[maxn],d[maxn];
LL h[maxn];
int L[maxn],R[maxn];

  inline void upd(int &x){
    s[x]=s[l[x]]+s[r[x]]+1;
    h[x]=md(h[r[x]]+pwr[s[r[x]]]*d[x]+pwr[s[r[x]]+1]*h[l[x]]);
  }
  inline void tl(int &x){
    int y=r[x];r[x]=l[y];l[y]=x;
    upd(x);upd(y);x=y;
  }
  inline void tr(int &x){
    int y=l[x];l[x]=r[y];r[y]=x;
    upd(x);upd(y);x=y;
  }
  void spl(int &x,int k){
    if(!x)return;
    int t,i;
    L[0]=R[0]=0;
    for(;;){
      t=s[l[x]]+1;
      if(k==t||(k<t&&!l[x])||(k>t&&!r[x]))break;
      if(k<t){
        if(l[l[x]]!=0&&k<s[l[l[x]]]){tr(x);if(!l[x])break;}
        R[++R[0]]=x; x=l[x];
      }else{
        k-=t;
        t=s[l[r[x]]]+1;
        if(r[r[x]]!=0&&k>t){k-=t;tl(x);if(!r[x])break;}
        L[++L[0]]=x; x=r[x];
      }
    }
    L[++L[0]]=l[x]; R[++R[0]]=r[x];
    for(i=L[0]-1;i;--i){r[L[i]]=L[i+1];upd(L[i]);}
    for(i=R[0]-1;i;--i){l[R[i]]=R[i+1];upd(R[i]);}
    l[x]=L[1]; r[x]=R[1]; upd(x);
  }

  inline void ist(int x,int w){
    spl(root,x+1); spl(r[root],1);
    l[r[root]]=++tot;
    s[tot]=1; d[tot]=h[tot]=w;
    upd(r[root]); upd(root);
  }
  inline void cng(int x,int w){
    spl(root,x+1);
    d[root]=w; upd(root);
  }
  inline LL geh(int x,int y){
    spl(root,x); spl(r[root],y-x+2);
    return h[l[r[root]]];
  }
  inline int query(int x,int y){
    if(x==y)return s[root]-x-1;
    if(x>y){int t=x;x=y;y=t;}
    int ans=0,L=1,R=s[root]-y-1,mid;
    LL hx=geh(x,x+R-1),hy=(y+R-1);
    if(hx==hy)return R;
    while(L<=R){
      mid=L+R>>1;
      if(s[l[root]]==x){
        hx=geh(x,x+mid-1);
        hy=geh(y,y+mid-1);
      }else{
        hy=geh(y,y+mid-1);
        hx=geh(x,x+mid-1);
      }
      if(hx==hy){
        if(ans<mid)ans=mid;
        L=mid+1;
      }else R=mid-1;
    }
    return ans;
  }

  inline int build(int L,int R){
    if(L>R)return 0;
    int mid=L+R>>1,p=++tot;
    s[p]=1; d[p]=org[mid];
    l[p]=build(L,mid-1);
    r[p]=build(mid+1,R);
    upd(p);
    return p;
  }

int main(){
  int i,M,x,y,n=0;
  char ch;

  ch=getchar();
  while(ch>='a'&&ch<='z'){
    org[++n]=ch-96;
    ch=getchar();
  }
  org[n+1]=org[0]=0;

  pwr[0]=1;
  for(i=1;i<maxn;++i)pwr[i]=md(pwr[i-1]*27);
  s[0]=l[0]=r[0]=d[0]=h[0]=0;

  root=build(0,n+1);
  scanf("%d",&M);
  while(M--){
    ch=getchar();
    while(ch!='Q'&&ch!='R'&&ch!='I')ch=getchar();
    if(ch=='Q'){
      scanf("%d%d",&x,&y);
      printf("%d\n",query(x,y));
    }else{
      scanf("%d",&x);
      y=getchar();
      while(y<'a'||y>'z')y=getchar();
      y-=96;
      if(ch=='R')cng(x,y);else ist(x,y);
    }
  }
  return 0;
}
