#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=10000000000009LL;
#define abs(x) (((x)<0)?(-(x)):(x))
#define A(x,y) ((x==y)?inf:abs((x)-(y)))
ll n,a[100005],b[100005],f[100005];
char buf[2000000],*p=buf;
inline int getint(){
    ll r=0; while(*p<'0'||*p>'9')p++; while(*p>='0'&&*p<='9')r=r*10+*p++-48;return r;
}int main(){
    fread(p,1,2000000,stdin);
    n=getint(); for(ll i=1;i<=n;i++)a[i]=getint(),b[i]=getint();
    sort(a+1,a+n+1);    sort(b+1,b+n+1);
    f[1]=A(a[1],b[1]);  f[2]=min(f[1]+A(a[2],b[2]),A(a[1],b[2])+A(a[2],b[1]));
    for(ll i=3;i<=n;i++)f[i]=min(f[i-1]+A(a[i],b[i]),min(f[i-2]+A(a[i-1],b[i])+A(a[i],b[i-1]),min(f[i-3]+A(a[i],b[i-1])+A(a[i-1],b[i-2])+A(a[i-2],b[i]),f[i-3]+A(a[i],b[i-2])+A(a[i-1],b[i])+A(a[i-2],b[i-1]))));
    printf("%lld\n",f[n]==inf?-1LL:f[n]);    return 0;
}
