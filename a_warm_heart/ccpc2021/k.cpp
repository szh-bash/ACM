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
#define mo 1000000007
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
#define N 205
const ll inf = 999999999ll * 9000000;
int n, m, k, p, w[N][N], c[N][N];
ll f[N][N][2], g[N][N][2];
char op[3];
void solve(){
    n=read(), m=read(), p=read();
    int sumw=0, sumc=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            w[i][j]=read();
            scanf("%s", op);
            c[i][j]=op[0]=='Y';
            sumw+=w[i][j];
            sumc+=c[i][j]^1;
        }
    if (sumc<p){
        cout<<sumw<<endl;
        return;
    }

    for (int i=1;i<=m;i++){ //colum
        int res=0;
        int k=n; // row
        int j=1; // bullet
        for (;k && c[k][i];k--) res+=w[k][i];
        g[i][0][1]=res;
        g[i][0][0]=-inf;
        for (;j<=p && k;j++,k--){
            res+=w[k][i];
            g[i][j][0]=res;
            if (k-1 && c[k-1][i]){
                --k;
                for (;k && c[k][i];k--) res+=w[k][i];
                ++k;
                g[i][j][1]=res;
            }
            else g[i][j][1]=-inf;
        }
        for (;j<=p;j++) g[i][j][0]=g[i][j][1]=-inf;
    }
    for (int j=0;j<=p;j++)
        f[0][j][0]=-inf,
        f[0][j][1]=0;
    for (int i=1;i<=m;i++)
        for (int j=0;j<=p;j++){
            f[i][j][0]=f[i-1][j][0];
            f[i][j][1]=f[i-1][j][1];
            for (int k=0;k<=j;k++)
                f[i][j][0]=max(f[i][j][0],
                                max(f[i-1][j-k][1]+g[i][k][0], f[i-1][j-k][0]+max(g[i][k][0],g[i][k][1]))),
                f[i][j][1]=max(f[i][j][1],f[i-1][j-k][1]+g[i][k][1]);
        }
    cout<<f[m][p][0]<<endl;
}
int main(){
    for (int _=read();_;_--) solve();
    return 0;
}