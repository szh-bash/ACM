#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt, next[30000], nu[30000], dfn[30000], low[30000], timee, top, stack[30000], flag[30000],  p[30000], ans1, ans2, ct, f[30000];

void add(int u, int v){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}

void tarjan(int u, int x){
     int j=next[u];
     dfn[u]=low[u]=++timee;
     flag[u]=1;
     stack[++top]=u;
     while (j){
           if ((j^x)!=1){
               int v=nu[j];
               if (!flag[v]) tarjan(v, j);
               if (dfn[u]<low[v]) ans1++;
               if (flag[v]<2) low[u]=min(low[u],low[v]);
           }
           j=next[j];
     }
     if (dfn[u]==low[u]){
         f[u]=++ct;flag[u]=2;
         while (stack[top--]!=u) flag[stack[top+1]]=2, f[stack[top+1]]=ct;
     }
}



int main(){
    scanf("%d%d", &n, &m);
    cnt=n;if (!(n%2))cnt++;
    for (int i=1;i<=m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add(u,v);add(v,u);
    }
    memset(flag,0,sizeof(flag));
    ct=timee=0;
    tarjan(1,0);
    printf("%d\n", ans1);
    memset(p,0,sizeof(p));
    for (int i=1;i<=n;i++){
        int j=next[i];
        while (j){
              int v=nu[j];
              if (f[v]!=f[i]) p[f[v]]++, p[f[i]]++;
              j=next[j];
        }
    }
    for (int i=1;i<=ct;i++) if (p[i]==2) ans2++;
    printf("%d\n", (ans2+1)/2);
    return 0;
}
