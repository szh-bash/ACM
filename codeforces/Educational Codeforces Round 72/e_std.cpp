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
#define LGN 12
#define N 300000
#define M 900000
#define mp make_pair
typedef long long ll;
using namespace std;
typedef pair<int, int> pii;
const int inf=1000000100;
int n, m, a[N];
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
pii f[LGN][M];
void pushup(int pos, int t){
	f[pos][t].first=min(f[pos][t<<1].first,f[pos][(t<<1)+1].first);
	f[pos][t].second=min(max(f[pos][t<<1].first,f[pos][(t<<1)+1].first),
						min(f[pos][t<<1].second,f[pos][(t<<1)+1].second));
}
void build(int pos, int t, int l,  int r){
	if (l==r){
		f[pos][t]=mp(inf, inf);
		return;
	}
	int mid=l+r>>1;
	build(pos, t<<1, l, mid);
	build(pos, (t<<1)+1, mid+1, r);
	pushup(pos, t);
}
void upd(int pos, int t, int l, int r, int x, int y){
	if (l==r){
		f[pos][t].first=y;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) upd(pos, t<<1, l, mid, x, y);
	else upd(pos, (t<<1)+1, mid+1, r, x, y);
	pushup(pos, t);
}
void update(int i, int x){
	int j=0;
	while (x){
		if (x%10) upd(j,1,1,n,i,a[i]);
		else upd(j,1,1,n,i,inf);
		x/=10;
		j++;
	}
	for (;j<LGN;j++)
		upd(j,1,1,n,i,inf);
}
pii query(int pos, int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return f[pos][t];
	int mid=l+r>>1;
	pii sl=mp(inf,inf), sr=mp(inf,inf), res;
	if (le<=mid) sl=query(pos,t<<1,l,mid,le,ri);
	if (ri>mid) sr=query(pos,(t<<1)+1,mid+1,r,le,ri);
	res.first=min(sl.first,sr.first);
	res.second=min(max(sl.first,sr.first),min(sl.second,sr.second));
	return res;
}
int main(){
	n=read(), m=read();
	for (int i=0;i<LGN;i++) build(i,1,1,n);
	for (int i=1;i<=n;i++)
		a[i]=read(),
		update(i,a[i]);
	while (m--){
		int op=read();
		if (op==1){
			int i=read();
			a[i]=read();
			update(i, a[i]);
		}
		else{
			int l=read(), r=read();
			int ans=inf+inf;
			for (int j=0;j<LGN;j++){
				pii p=query(j, 1, 1, n, l, r);
				if (p.second==inf) continue;
				ans=min(ans, p.first+p.second);
			}
			printf("%d\n", ans==inf+inf?-1:ans);
		}
	}
	return 0;
}
