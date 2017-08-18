#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int top, n, cnt, ct, ti, p1, p2, next[11000], nu[11000], low[110], dfn[110], f[110], flag[110], stack[110], out[110], in[110];
void add(int u, int v){
     next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;
}
void tarjan(int u){
     stack[++top]=u;
     low[u]=dfn[u]=++ti;
     flag[u]=1;
     int j=next[u];
     while (j){
           int v=nu[j];
           if (!flag[v]) tarjan(v);
           if (flag[v]<2) low[u]=min(low[u],low[v]);
           j=next[j];
     }
     if (low[u]==dfn[u]){
         flag[u]=2;f[u]=++ct;
         while (stack[top--]!=u) flag[stack[top+1]]=2, f[stack[top+1]]=ct;
     }
}
int main(){
    scanf("%d", &n);
    cnt=n;
    for (int i=1;i<=n;i++){
        int v;
        scanf("%d", &v);
        while (v){
              add(i,v);
              scanf("%d", &v);
        }
    }
    ct=ti=0;
    for (int i=1;i<=n;i++) if (!flag[i]) tarjan(i);
    for (int i=1;i<=n;i++){
        int j=next[i];
        while (j){
              int v=nu[j];
              if (f[v]!=f[i]){
                              out[f[i]]++;
                              in[f[v]]++;
                              }
              j=next[j];
        }
    }
    for (int i=1;i<=ct;i++){
        if (!in[i]) p1++;
        if (!out[i])p2++;
    }
    p2=max(p1,p2);
    if (ct==1) p2=0;
    printf("%d\n%d\n", p1, p2);
    system("pause");
    return 0;
}
