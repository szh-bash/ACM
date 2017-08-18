#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, p, fo[300], a[300][300], w[300][300], U[300], c[300], fi[300], ri, l[300];
int main(){
    freopen("std.in","r",stdin);
    freopen("std.out","w",stdout);
    scanf("%d%d", &n, &p);
    for (int i=1;i<=n;i++){
        scanf("%d%d", &c[i], &U[i]);
        if (c[i]>0) l[++ri]=i;
    }
    int u, v;
    for (int i=1;i<=p;i++){
        scanf("%d%d", &u, &v);
        a[u][v]=1;
        fi[v]++;
        fo[u]++;
        scanf("%d", &w[u][v]);
    }
    for (int i=1;i<=ri;i++){
        v=l[i];
        for (int j=1;j<=n;j++)
            if (a[v][j]){
                fi[j]--;
                if (!fi[j]) {
                    l[++ri]=j;
                    c[j]-=U[j];
                }
                if (c[v]>0) c[j]+=w[v][j]*c[v];
            }
    }
    int flag=0;
    for (int i=1;i<=n;i++)
        if (!fo[i] && c[i]>0){
            flag=1;
            printf("%d %d\n", i, c[i]);
        }
    if (!flag) printf("NULL\n");
    return 0;
}
