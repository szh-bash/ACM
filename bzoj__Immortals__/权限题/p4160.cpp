#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 16
#define M 1<<15
#define INF 16
using namespace std;
int n, m, ct, f[M], w[M], list[N], a[100];
bool map[N][N];
void init(){
    cin>>m;
    for (int i=1;i<=m;i++){
        char s1[2], s2[2];
        int u, v;
        scanf("%s%s", s1, s2);
        if (!(u=a[s1[0]])) u=a[s1[0]]=++n;
        if (!(v=a[s2[0]])) v=a[s2[0]]=++n;
        map[u][v]=map[v][u]=1;
    }
}
void pre(){
    int k=(1<<n);
    for (int i=0;i<k;i++){
        f[i]=INF;
        int cnt=0, flag=i;
        for (int j=1;j<=n;j++)
            if (i&(1<<j-1)){
                for (int q=1;q<=cnt;q++)
                    if (map[list[q]][j]){
                        flag=0;
                        break;
                    }
                if (!flag) break;
                list[++cnt]=j;
            }
        if (flag) w[++ct]=i;
    }
    f[0]=0;
}
int dfs(int x){
    if (f[x]!=INF) return f[x];
    for (int i=1;i<=ct;i++)
        if ((w[i]&x)==w[i])
            f[x]=min(dfs(x^w[i])+1,f[x]);
    return f[x];
}
int main(){
    init();
    pre();
    cout<<dfs((1<<n)-1)-2<<endl;
    return 0;
}
