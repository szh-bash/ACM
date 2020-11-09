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
int n, m, bit[M], inv[M], a[N];
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
inline f1(int x, int i, int y){
    return max(0,(m>=x?bit[m-x]:0)-(x>20?1:((n-i)/bit[x]+1)));
}

void solve(){
    int sum=0;
    for (int i=1;i<=n;i++){
        int x=a[i]=read();
        int res=dec(f1(x-1, i, 0),f1(x, i, bit[x-1]));
        res = dec(res,x>20?0:((i-1)/bit[x-1]-(i-1)/bit[x]));
        res = dec(dec(bit[m],n),res);
        sum=add(sum,res);
    }
    printf("%d ", sum);
    puts("");
}
int main(){
    int inv2=power(2, mo-2);
    inv[0]=bit[0]=1;
    for (int i=1;i<M;i++) inv[i]=1ll*inv[i-1]*inv2%mo, bit[i]=add(bit[i-1], bit[i-1]);
    while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
