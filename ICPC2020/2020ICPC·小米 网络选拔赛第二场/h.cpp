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
#define N 200005
#define M 2005
#define res 301 
int n, m;
ll f[M];
struct node{
	int w, v;
}l[N];
inline bool cmp(node &a, node &b){
	return 1ll*a.v*b.w>1ll*b.v*a.w;
}
void solve(){
	for (int i=1;i<=n;i++) l[i].w=read(), l[i].v=read();
	sort(l+1,l+1+n,cmp);
	int dm=max(m-res,0);
	int i=1;
	ll ans=0;
	for (;i<=n && l[i].w<=dm;i++)
		dm-=l[i].w,
		ans+=l[i].v;
	
	m=min(m,res)+dm;
	for (int j=0;j<=m;j++) f[j]=0;
	for (;i<=n;i++)
		for (int j=m;j>=l[i].w;j--)
			if (f[j]<f[j-l[i].w]+l[i].v)
				f[j]=f[j-l[i].w]+l[i].v;
	printf("%lld\n", ans+f[m]);
}
int main(){
	while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
