#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m, flag[4000], res[4000], nu[4000], next[4000], cnt, ans;
int dfs(int t){
    int j=next[t], u;
    while(j){
             u=nu[j];
             if (!flag[u]){
               flag[u]=1;
               if (!res[u] || dfs(res[u])){
                         res[u]=t;
                         return 1;
                         }
             }
             j=next[j];
    }
    return 0;
}
int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d", &n, &m);
    getchar();
    cnt=n+m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char a;
            scanf("%c", &a);
            if (a=='1'){
                        next[++cnt]=next[i];next[i]=cnt;nu[cnt]=j+n;
                        next[++cnt]=next[j+n];next[j+n]=cnt;nu[cnt]=i;
                        }
        }
        getchar();
    }
    for (int i=1;i<=n;i++){
                  memset(flag,0,sizeof(flag));
                  if (dfs(i)) ans++;
                  }
    printf("%d\n", ans);
    return 0;
}
