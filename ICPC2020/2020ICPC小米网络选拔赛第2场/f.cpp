#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 1005
#define mo 1000000007
#define inv 333333336
int n, m, sum[N], f[N][N], l[N];
inline void add(int &a, int b){
    a+=b;
    if (a>=mo) a-=mo;
}
inline void dec(int &a, int b){
    a-=b;
    if (a<0) a+=mo;
}
void solve(){
    sum[0]=f[0][0]=1;
    for (int i=1;i<=n;i++) l[i]=sum[i]=0;
    for (int i=1;i<=m;i++){
        int x=read(), y=read();
        l[y]=max(l[y], x);
    }
    for (int i=1;i<=n;i++) l[i]=max(l[i-1],l[i]);
    for (int i=1;i<=n;i++){
        f[i][i]=0;
        for (int j=l[i];j<i;j++) f[i][j]=1ll*inv*sum[j]%mo, add(sum[i],f[i][j]);
        for (int j=l[i-1];j<i;j++) add(f[i][i],sum[j]);
        f[i][i]=1ll*f[i][i]*inv%mo;
        add(sum[i],f[i][i]);
        for (int j=l[i-1];j<i;j++)
            for (int k=l[i-1];k<=min(l[i]-1,j);k++)
                dec(sum[j],f[j][k]),
                f[j][k]=0;
    }
    int ans=0;
    for (int i=l[n];i<=n;i++) add(ans,sum[i]);
    for (int i=1;i<=n;i++) ans=6ll*ans%mo;
    printf("%d\n", ans);
}
int main(){
    while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
