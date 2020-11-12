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
#include <unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
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
#define N 1000000
int n, m, a[N], b[N];
void solve(){
    int pm=(1<<m)-1;
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=m;i++){
        int d=1<<(i-1);
        for (int j=d;j<=pm;j+=d)
            b[j]=i;
    }
    // for (int i=1;i<=pm;i++) cout<<b[i]<<' ';
    // cout<<endl;
    int ans=n+1, sum=0;
    for (int i=1;i+n-1<=pm;i++){
        int res=0;
        for (int j=1;j<=n;j++)
            if (a[j]!=b[i+j-1]) res++;
        sum+=res;
        ans=min(ans,res);
    }
    cout<<ans<<' '<<sum<<endl;
}
int main(){
    freopen("data.in","r",stdin);
    freopen("bf.out","w",stdout);
    while (cin>>n>>m) solve();
}