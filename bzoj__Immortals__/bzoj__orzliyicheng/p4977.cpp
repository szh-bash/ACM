#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
#define INF 1000000000
typedef long long ll;
using namespace std;
int n, m, x, cnt, g[N*2], a[N], b[N], c[N], d[N];
int ans[N], f[N*2];
ll ans_;
char s[2100000];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
bool cmp(int x, int y){return b[x]<b[y];}
void add(int t, int l, int r, int x, int y){
	if (l==r){
		f[g[t]=t]=y;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) add(t<<1,l,mid,x,y);else add((t<<1)+1,mid+1,r,x,y);
	if (f[t<<1]>f[(t<<1)+1])
		f[t]=f[g[t]=g[t<<1]];
	else
		f[t]=f[g[t]=g[(t<<1)+1]];
}
int query(int t, int l, int r, int x){
	if (r<=x) return g[t];
	int mid=l+r>>1, tmp1=query(t<<1,l,mid,x), tmp2=0;
	if (x>mid) tmp2=query((t<<1)+1,mid+1,r,x);
	if (f[tmp1]>f[tmp2]) return tmp1;else return tmp2;
}
void modify(int x){
	f[g[x]=x]=-INF;
	while (x/=2)
		if (f[x<<1]>f[(x<<1)+1])
			f[x]=f[g[x]=g[x<<1]];
		else
			f[x]=f[g[x]=g[(x<<1)+1]];
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.ans","w",stdout);
	f[0]=-INF;
	fread(s,1,2000000,stdin);
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read(), c[i]=read(), d[i]=i;
	sort(a+1,a+1+n);
	sort(d+1,d+1+m,cmp);
	for (int i=1, j=1;i<=n;i++){
		while (j<=m && b[d[j]]<a[i]) add(1,1,m,j,-b[d[j]]+c[d[j]]), j++;
		if (cnt==j-1) continue;
		ll v=query(1,1,m,j-1);
		ans[++cnt]=f[v];
		modify(v);
	}
	sort(ans+1,ans+1+cnt);
	for (int i=1;i<=cnt;i++)
		if (ans[i]+a[n-cnt+i]>0) ans_+=ans[i]+a[n-cnt+i];
	cout<<ans_<<endl;
	return 0;
}
