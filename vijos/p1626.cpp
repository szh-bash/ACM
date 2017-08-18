#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, m, cnt, ct, ti, ans, top, next[12000], nu[12000], p[2000], f[2000], low[2000], dfn[2000], stack[2000], flag[2000], ff[2000];
void add(int u, int v){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void tarjan(int u){
     flag[u]=1;
     stack[++top]=u;
     dfn[u]=low[u]=++ti;
     int j=next[u];
     while (j){
           int v=nu[j];
           if (!flag[v]) tarjan(v);
           if (flag[v]<2) low[u]=min(low[u],low[v]);
           j=next[j];
     }
     if (low[u]==dfn[u]){
         flag[u]=2;f[u]=++ct;
         if (stack[top]!=u) ans++, ff[ct]=1;
         while (stack[top--]!=u) flag[stack[top+1]]=2, f[stack[top+1]]=ct;
     }
}
int main(){
    scanf("%d%d", &n, &m);
    cnt=n;
    for (int i=1;i<=m;i++){
        int u, v;
        scanf("%d%d", &u, &v);
        add(u,v);
    }
    for (int i=1;i<=n;i++) if (!flag[i]) tarjan(i);
    int tmp=ct;
    for (int i=1;i<=n;i++){
        int j=next[i];
        while (j){
              int v=nu[j];
              if (f[v]!=f[i]) p[f[i]]++;
              j=next[j];
        }
    }
    for (int i=1;i<=ct;i++)if (p[i]) tmp--;
    printf("%d\n", ans);
    if (tmp!=1)printf("-1\n");
    else{
         for (int i=1;i<=n;i++)
             if (!p[f[i]]) {cnt=f[i];break;}
         if (!ff[cnt]) printf("-1\n");
         else
             for (int i=1;i<=n;i++)
                 if (f[i]==cnt) printf("%d ", i);
         }
    system("pause");
    return 0;
}
