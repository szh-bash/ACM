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
#define num(x) ((x)>='0' && (x)<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
#define DATA 2000000*8
char s[DATA];
int pos;
int read(){
    int p=0;
    while (s[pos] && (!num(s[pos]))) pos++;
    while (num(s[pos])) p=p*10+s[pos++]-'0';
    return p;
}
#define LGN 22
#define N 100005
#define M 100005
#define mo 1000000007
int n, m, bit[M], a[N];
inline void dec(int &a, int b){
    a-=b;
    if (a<0) a+=mo;
}
inline void add(int &a, int b){
    a+=b;
    if (a>=mo) a-=mo;
}
inline int f(int x, int i){
    int res=bit[m-x]-(x>20?0:(n-i)/bit[x])-1;
    if (res<0) res+=mo;
    return res;
}
int g[LGN][N][3], sz[LGN][N], mp[LGN][N];
void solve(){
    int sum=0;
    for (int i=1;i<=n;i++){
        int x=a[i]=read();
        int res=f(x-1, i);dec(res,f(x, i));
        dec(res,x>20?0:((i-1)/bit[x-1]-(i-1)/bit[x]));
        int tr=bit[m];dec(tr,n);
        dec(tr,res);
        add(sum,tr);
    }
    int ans=n+1;
    for (int j=0;bit[j]<=n*4;j++){
        for (int i=0;i<bit[j];i++) 
            g[j][i][0]=g[j][i][1]=g[j][i][2]=sz[j][i]=0;
        for (int i=1;i<=n;i++)
            mp[j][i]=i%bit[j],
            g[j][mp[j][i]][(a[i]==j+1)?1:(a[i]==j?0:2)]++,
            sz[j][mp[j][i]]++;
    }
    for (int i=1;i<=n;i++){
        int md=1, res=0, flag=0;
        for (int j=1;j<=m;j++)
            if (bit[j-1]-1>=max(i-1,n-i)){
                flag=1;
                if (m<20 && bit[j-1]+n-i>bit[m]-1){
                    flag=0;
                    break;
                }
                if ((j<=a[i]) && (m>20 || bit[a[i]-1]+n-i<=bit[m]-1)) md=0;
                break;
            }
        if (!flag) continue;
        for (int j=1;bit[j-1]<=max(i-1,n-i);j++)
            res+=sz[j-1][mp[j-1][i]]-sz[j][mp[j][i]]-(g[j-1][mp[j-1][i]][1]-g[j][mp[j][i]][0]);
        ans=min(ans,md+res);
    }
    printf("%d %d\n", ans, sum);
}
int main(){
    freopen("data.in","r",stdin);
    freopen("std.out","w",stdout);
    fread(s,1,DATA,stdin);
    bit[0]=1;
    for (int i=1;i<M;i++) bit[i]=1ll*bit[i-1]*2%mo;
    while ((n=read()) && (m=read())) solve();
    return 0;
}
