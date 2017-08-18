#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int ans, a, r, t, n, m, cnt, res[10000], flag[10000], next[2000000], nu[2000000];
double  x[10000], y[10000], v[10000];
double sqr(double x){return x*x;}
int ff(int a, int b){
    if (v[a]*t>=sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]))) return 1;return 0;
}
int dfs(int t){
    int u, j=next[t];
    while (j){
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
    scanf("%d%d%d", &r, &a, &t);
    for (int i=1;i<=a;i++) scanf("%lf%lf", &x[r+i], &y[r+i]);
    for (int i=1;i<=r;i++) scanf("%lf%lf%lf", &x[i], &y[i], &v[i]);
    cnt=a+r;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=a;j++)
            if (ff(i,j+r)){
                         next[++cnt]=next[i];next[i]=cnt;nu[cnt]=r+j;
                         next[++cnt]=next[j+r];next[j+r]=cnt;nu[cnt]=i;
                        }
    for (int i=1;i<=r;i++){
        memset(flag,0,sizeof(flag));
        if (dfs(i)) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
