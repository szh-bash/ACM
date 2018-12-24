#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define K 6
#define B 35
#define N 200005
#define M 900000
#define INF 300000000
typedef long long ll;
using namespace std;
int n, k, d, x, le, ri, b[K], bit[K], a[N][K], va[B][N];
int f[B][M], g[B][M], ls[M], rs[M];
char s[200000*100];
int read(){
	int p=0, q=1;
	while (s[x]<'0' || s[x]>'9') s[x++]=='-'?q=-1:0;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p*q;
}
void upd(int id, int t, int l, int r, int x, int v){
	if (l==r) { f[id][t]=g[id][t]=v; return;}
	int mid=l+r>>1;
	if (x<=mid) upd(id, ls[t], l, mid, x, v);
	else upd(id, rs[t], mid+1, r, x, v);
	f[id][t]=max(f[id][ls[t]], f[id][rs[t]]);
	g[id][t]=min(g[id][ls[t]], g[id][rs[t]]);
}
int getMin(int id, int t, int l, int r){
	if (le<=l && r<=ri) return g[id][t];
	int mid=l+r>>1, p0=INF, p1=INF;
	if (le<=mid) p0=getMin(id, ls[t], l, mid);
	if (ri>mid) p1=getMin(id, rs[t], mid+1, r);
	return min(p0, p1);
}
int getMax(int id, int t, int l, int r){
	if (le<=l && r<=ri) return f[id][t];
	int mid=l+r>>1, p0=-INF, p1=-INF;
	if (le<=mid) p0=getMax(id, ls[t], l, mid);
	if (ri>mid) p1=getMax(id, rs[t], mid+1, r);
	return max(p0, p1);
}
void build(int id, int t, int l, int r){
	if (l==r){
		f[id][t]=g[id][t]=va[id][l];
		return;
	}
	int mid=l+r>>1;
	ls[t]=t<<1;
	rs[t]=(t<<1)+1;
	build(id, ls[t], l, mid);
	build(id, rs[t], mid+1, r);
	f[id][t]=max(f[id][ls[t]], f[id][rs[t]]);
	g[id][t]=min(g[id][ls[t]], g[id][rs[t]]);
}
int main(){
	fread(s,1,200000*99,stdin);
	n=read();k=read();
	d=(1<<k);
	bit[0]=1;
	for (int i=1;i<=k;i++) bit[i]=bit[i-1]<<1;
	for (int i=1;i<=n;i++)
		for (int w=0;w<k;w++) a[i][w]=read();
	for (int i=1;i<=n;i++)
		for (int j=0;j<d;j++)
			for (int w=0;w<k;w++)
				if (j&bit[w]) va[j][i]-=a[i][w];else va[j][i]+=a[i][w];
	for (int j=0;j<d;j++) build(j,1,1,n);
	for (int _=read();_;_--){
		int op=read();
		if (op==1){
			int i=read();
			for (int w=0;w<k;w++) b[w]=read();
			for (int j=0;j<d;j++){
				int v=0;
				for (int w=0;w<k;w++)
					if (j&bit[w]) v-=b[w];else v+=b[w];
				upd(j,1,1,n,i,v);
			}
		}
		else{
			le=read(), ri=read();
			int ans=0;
			for (int j=0;j<d;j++)
				ans=max(ans,getMax(j,1,1,n)-getMin(j,1,1,n));
			printf("%d\n", ans);
		}
	}
	return 0;
}
