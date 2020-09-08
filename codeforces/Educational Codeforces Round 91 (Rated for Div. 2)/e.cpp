#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 200005
#define M N*3
int n, m, cnt, a[N], nex[M], nu[M], le[M], ri[M], num[N], tail[N];
void add(int u, int l, int r){
	nex[++cnt]=nex[u];nex[u]=cnt;le[cnt]=l;ri[cnt]=r;num[u]++;
	if (!nex[cnt]) tail[u]=cnt;
}
int fa[N], ans;
void build(){
	int sum=1;
	cnt=m;
	ans=-1;
	for (int i=2;i<=n+1;i++)
		if (a[i]!=a[i-1])
			add(a[i-1], i-sum, i-1),
			sum=1,
			ans++;
		else
			sum++;
	
}
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
void solve(){
	int x=father(read()), y=father(read());
	if (num[x]>num[y]) swap(x,y);
	for (int j=nex[x];j;j=nex[j]){
		int l=le[j], r=ri[j];
		ans-=(father(a[l-1])==y)+(father(a[r+1])==y);
	}
	nex[tail[y]]=nex[x];
	tail[y]=tail[x];
	num[y]+=num[x];
	fa[x]=y;
	printf("%d\n", ans);
}
int main(){
	n=read(), m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) fa[i]=i;
	build();
	printf("%d\n", ans);
	for (int _=m-1;_;_--) solve();
	return 0;
}
