#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 500000
#define mo 1000000007
typedef long long ll;
using namespace std;
int h, w, n, f[N], p[N], ww[N];
ll ans;
vector <ll> g[N];
vector <int> stack[N];
struct qlz{
	int row, l, r, s;
}l[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
bool cmp(qlz a, qlz b){return a.row>b.row;}
void update(int t, int l, int r, int u, int x){
	if (l==r){
		f[ww[l]=t]=x;
		p[t]=l;
		return;
	}
	int mid=l+r>>1;
	if (u<=mid) update(t<<1,l,mid,u,x);
	if (u>mid) update((t<<1)+1,mid+1,r,u,x);
	if (f[t<<1]<f[(t<<1)+1]) f[t]=f[ww[p[t]=p[t<<1]]];
	else f[t]=f[ww[p[t]=p[(t<<1)+1]]];
}
void add(int u, int x, int y){
	if (stack[u][stack[u].size()-1]!=x)
		stack[u].push_back(x),
		g[u].push_back(0),
		update(1,1,w,u,x);
	g[u][g[u].size()-1]+=y;
	if (g[u][g[u].size()-1]>mo) g[u][g[u].size()-1]%=mo;
}
int find(int t, int l, int r, int le, int ri){
	if (le<=l && r<=ri) return p[t];
	int mid=l+r>>1, tp1=0, tp2=0;
	if (le<=mid) tp1=find(t<<1,l,mid,le,ri);
	if (ri>mid) tp2=find((t<<1)+1,mid+1,r,le,ri);
	if (f[ww[tp1]]<f[ww[tp2]]) return tp1;else return tp2;
}
int main(){
	h=read();w=read();n=read();
	f[0]=mo*2;
	for (int i=1;i<=n;i++) l[i].row=read(), l[i].l=read(), l[i].r=read(), l[i].s=read()+l[i].row;
	sort(l+1,l+1+n,cmp);
	for (int i=1;i<=w;i++)
		stack[i].push_back(0),
		g[i].push_back(0),
		add(i,h+1,1);
	for (int i=1;i<=n;i++){
		int t, le=l[i].l, ri=l[i].r, ls=l[i].s, row=l[i].row;
		while (f[ww[t=find(1,1,w,le,ri)]]<=ls){
			stack[t].pop_back();
			int x=stack[t][stack[t].size()-1], y=g[t][g[t].size()-1];
			g[t].pop_back();
			update(1,1,w,t,x?x:mo*2);
			if (le==1) add(ri+1,row,2*y);
			else
				if (ri==w) add(le-1,row,2*y);
				else
					add(le-1,row,y),
					add(ri+1,row,y);
		}
	}
	for (int i=1;i<=w;i++)
		for (int j=1;j<g[i].size();j++){
			ans+=g[i][j];
			if (ans>mo) ans%=mo;
		}
	cout<<ans<<endl;
	return 0;
}
