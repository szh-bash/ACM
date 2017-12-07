#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, tp, a[110000], ans[1000100], c[110000], p[110000], f[110000];
struct zsm{
	int l, r, a, b, n;
}l[1000100];
bool cmp(zsm a, zsm b){
	if (p[a.l]<p[b.l]) return 1;
	if (p[a.l]>p[b.l]) return 0;
	return a.r<b.r;
}
void solve(){
	int le=1, ri=tp, i=1;
	while (le<=n && i<=m){
		int j2=le-1, j1=le;
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		while (i<=m && l[i].l>=le && l[i].l<=ri){
			int num=l[i].n;
			while (j2<l[i].r) c[a[++j2]]++?1:f[p[a[j2]]]++;
			while (j1<l[i].l) --c[a[j1++]]?1:f[p[a[j1-1]]]--;
			while (j1>l[i].l) c[a[--j1]]++?1:f[p[a[j1]]]++;
			int k;
			for (k=1;k<p[l[i].b];k++) ans[num]+=f[k];
			for (k=(k-1)*tp+1;k<=l[i].b;k++) ans[num]+=c[k]?1:0;
			for (k=1;k<p[l[i].a];k++) ans[num]-=f[k];
			for (k=(k-1)*tp+1;k<=l[i].a;k++) ans[num]-=c[k]?1:0;
			++i;
		}
		le+=tp;ri+=tp;
	}
}
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	cin>>n>>m;
	return 0;
	tp=sqrt(n);
	for (int i=1;i<=n;i++) scanf("%d", &a[i]), p[i]=(i-1)/tp+1;
	for (int i=1;i<=m;i++){
		l[i].l=read();
		l[i].r=read();
		l[i].a=read()-1;
		l[i].b=read();
		l[i].n=i;
	}
	sort(l+1,l+1+m,cmp);
	solve();
	for (int i=1;i<=m;i++) printf("%d\n", ans[i]);
	return 0;
}
