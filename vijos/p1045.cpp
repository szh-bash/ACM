#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
struct zsm{
          int u, v;
          double w;
    };
int n,m,num[302],fa[302],q;
zsm l[100002];
int cmp(zsm a,zsm b){
    return a.w<b.w;
}
int father(int x){
    if (fa[x]==x) return x;
    fa[x]=father(fa[x]);
    return fa[x];    
}
void uni(int u,int v){
     num[fa[v]]+=num[fa[u]];
     fa[fa[u]]=fa[v];
}
int main()
{
      scanf("%lf", &s);
      scanf("%d%d", &n, &m);
      for (int i=1;i<=m;i++)
          scanf("%d%d%lf", &l[i].u, &l[i].v, &l[i].w);
      sort(l+1,l+m+1,cmp);
      for (int i=1;i<=n;i++){
          fa[i]=i;
          num[i]=1;
      }
      for (int i=1;i<=m;i++)
          if (father(l[i].u)!=father(l[i].v)){
              uni(l[i].u,l[i].v);
              q++;
              if (num[fa[l[i].v]]==n){
                  cout<<q<<' '<<l[i].w<<endl;
                  break;
              }
          }
      return 0;
}
