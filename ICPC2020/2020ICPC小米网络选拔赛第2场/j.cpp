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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
#define M 100005
#define mo 1000000007
int n, m, bit[M], a[N];
int power(ll a, int b){
    ll c=1;
    while (b){
        if (b&1) c=c*a%mo;
        a=a*a%mo;
        b>>=1;
    }
    return c;
}
inline int dec(int a, int b){
    a-=b;
    if (a<0) a+=mo;
    return a;
}
inline int add(int a, int b){
    a+=b;
    if (a>=mo) a-=mo;
    return a;
}
inline int f(int x, int i){
    int res=bit[m-x]-(x>20?0:(n-i)/bit[x])-1;
    if (res<0) res+=mo;
    return res;
}
int g[20][N][3], sz[20][N];
void solve(){
    int sum=0;
    for (int i=1;i<=n;i++){
        int x=a[i]=read();
        int res=dec(f(x-1, i),f(x, i));
        res = dec(res,x>20?0:((i-1)/bit[x-1]-(i-1)/bit[x]));
        res = dec(dec(bit[m],n),res);
        sum=add(sum,res);
    }
    int ans=n+1;
    for (int j=0;bit[j]<=n;j++){
        for (int i=0;i<=min(bit[j]-1,n);i++) 
            g[j][i][0]=g[j][i][1]=g[j][i][2]=sz[j][i]=0;
        for (int i=1;i<=n;i++)
            g[j][i%bit[j]][(a[i]==j+1)?1:(a[i]==j?0:2)]++,
            sz[j][i%bit[j]]++;
    }
    for (int i=1;i<=n;i++){
        int md=1, res=0;
        for (int j=1;j<=m;j++)
            if (bit[j-1]-1>=max(i-1,n-i)){
                if (j<=a[i]) md=0;
                break;
            }
        for (int j=1;bit[j-1]<=max(i-1,n-i);j++){
            res+=sz[j-1][i%bit[j-1]]-sz[j][i%bit[j]]
                -(g[j-1][i%bit[j-1]][1]-g[j][i%bit[j]][0]);
            // cout<<"min: "<<i<<' '<<res<<' '<<sz[j-1][i%bit[j-1]]-sz[j][i%bit[j]]<<' '<<(g[j-1][i%bit[j-1]][1]-g[j][i%bit[j]][0])<<endl;
        }
        ans=min(ans,md+res);
    }
    printf("%d %d\n", ans, sum);
}
int main(){
    bit[0]=1;
    for (int i=1;i<M;i++) bit[i]=add(bit[i-1], bit[i-1]);
    while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
