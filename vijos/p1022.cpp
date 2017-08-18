#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int n, flag[300], dfn[300], low[300], stac[300], top, ans, a[300][300], tim;
void init(){
     scanf("%d", &n);
     int u;
     for (int i=1;i<=n;i++){
         scanf("%d", &u);
         while (u){
               a[i][u]=1;
               scanf("%d", &u);
               }
     }
}
void dfs(int t){
     stac[++top]=t;
     flag[t]=1;
     dfn[t]=low[t]=++tim;
     for (int i=1;i<=n;i++)
       if (a[t][i]){
                    if (!flag[i]) dfs(i);
                    if (flag[i]<2) low[t]=min(low[t],low[i]);
                    }
     if (low[t]==dfn[t]){
                         ans++;
                         while(stac[top--]!=t) flag[stac[top+1]]=2;
                         }
}
int tarjan(){
    for (int i=1;i<=n;i++)
        if (!flag[i]) dfs(i);
    return ans;
}
int main(){
    init();
    printf("%d\n", tarjan());
    system("pause");
    return 0;
}
