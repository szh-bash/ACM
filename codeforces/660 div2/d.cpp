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
int n;
ll ans, a[N], b[N];
int d[N], flag[N];
int l[N], f[N];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), d[i]=flag[i]=0;
	for (int i=1;i<=n;i++){
		b[i]=read();
		if (b[i]>=0) d[b[i]]++;
	}
	int head=0, tail=0;
	for (int i=1;i<=n;i++)
		if (!d[i]) l[++tail]=i;
	int cnt=0;
	ans=0;
	while (head<tail){
		int u=l[++head];
		if (a[u]<0){
			f[++cnt]=u;
			if (b[u]>=0 && !--d[b[u]]) l[++tail]=b[u];
			flag[u]=1;
		}
		else{
			ans+=a[u];
			if (b[u]>=0){
				a[b[u]]+=a[u];
				if (!--d[b[u]]) l[++tail]=b[u];
			}
		}
	}
	for (int i=cnt;i;i--) ans+=a[f[i]];
	printf("%I64d\n", ans);
	for (int i=1;i<=tail;i++)
		if (!flag[l[i]]) printf("%d ", l[i]);
	for (int i=cnt;i;i--) printf("%d ", f[i]);
	puts("");
}
int main(){
	solve();
	return 0;
}
