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
#define N 500000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, top, trans[N], a[N], stf[N];
ll c[N], st[N];
map<int, int> mp;
struct zsa{
	int b, f, w;
}l[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmp(zsa a, zsa b){
	if (a.b<b.b) return 1;
	if (a.b>b.b) return 0;
	return a.f<b.f;
}
int main(){
	while (~scanf("%d", &n)){
		int cnt=0, ct=0;
		for (int i=1;i<=n;i++)
			a[++cnt]=l[i].b=read(),
			a[++cnt]=l[i].f=read(),
			a[++cnt]=l[i].w=read();
		sort(a+1,a+1+cnt);
		mp.clear();
		for (int i=1;i<=cnt;i++)
			if (a[i]!=a[i-1]) trans[mp[a[i]]=++ct]=a[i];
		sort(l+1,l+1+n,cmp);
		for (int i=1;i<=ct;i++) c[i]=0;
		for (int i=1;i<=n;){
			int j=i+1;
			ll w=l[i].w, va=0;
			while (j<=n && l[j].b==l[i].b && l[j].f==l[i].f) w+=l[j++].w;
			for (int k=mp[l[i].f]-1;k;k-=k&(-k)) va=max(va,c[k]);
			w+=va;
			st[++top]=w;
			stf[top]=mp[l[i].f];
			if (j>n || l[j].b!=l[i].b)
				while (top){
					for (int k=stf[top];k<=ct;k+=k&(-k)) c[k]=max(c[k],st[top]);
					top--;
				}
			i=j;
		}
		ll ans=0;
		for (int k=ct;k;k-=k&(-k)) ans=max(ans,c[k]);
		printf("%lld\n", ans);
	}
    return 0;
}
