#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, t, p, b[21], a[21], flag[21], f[21][21][21];
int maxs(int d){
    int j=d, tmp=0, f[21], p;
    memset(f, 0, sizeof(f));
    for (int i=1;i<=n;i++)
        if (!flag[i]){
            int min=999999999;
            for (int j=d;j<=n;j++)
                if (!f[j] && a[j]<min){
                    min=a[j];
                    p=j;
                }
            tmp+=i*a[p];
            f[p]=1;
        }
    return tmp;
}
int mins(int d){
    int j=n, tmp=0, f[21], p;
    memset(f, 0, sizeof(f));
    for (int i=1;i<=n;i++)
        if (!flag[i]){
            int max=0;
            for (int j=d;j<=n;j++)
                if (!f[j] && a[j]>max){
                    max=a[j];
                    p=j;
                }
            tmp+=i*a[p];
            f[p]=1;
        }
    return tmp;
}
int dfs(int d){
    if (d>n){
        if (p==t) return 1;
        return 0;
    }
    if (maxs(d)+p<t || mins(d)+p>t) return 0;
    for (int i=1;i<=n;i++)
        if (!flag[i]){
            if (d>n/2+n%2 && b[n-d+1]>i) continue;
            flag[i]=1;
            b[d]=i;
            p+=i*a[d];
            if (dfs(d+1)) return 1;
            p-=i*a[d];
            flag[i]=0;
        }
    return 0;
}
int main(){
    while (scanf("%d%d", &n, &t)!=EOF){
        memset(flag,0,sizeof(flag));
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++) f[1][i][i]=1;
        for (int i=2;i<=n;i++)
            for (int j=1;j<=n-i+1;j++)
                for (int k=1;k<=n;k++)
                    f[i][j][k]=f[i-1][j][k]+f[i-1][j+1][k];
        for (int i=1;i<=n;i++) a[i]=f[n][1][i];
        p=0;
        dfs(1);
        for (int i=1;i<n;i++) printf("%d ", b[i]);printf("%d\n", b[n]);
    }
}
