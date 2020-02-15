#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 400005
#define NLGN N*21
using namespace std;
int n, m, cnt, root[N];
int size[NLGN], fa[NLGN], ls[NLGN], rs[NLGN], tag[NLGN];
struct oprate{
	int op, x, y;
}l[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int query(int t, int l, int r, int x){
	if (l==r) return t;
	int mid=l+r>>1;
	if (x<=mid) return query(ls[t],l,mid,x);
	return query(rs[t],mid+1,r,x);
}
int find(int t, int x){
	int v=query(t,1,n,x);
	if (x==fa[v]) return v;
	return find(t,fa[v]);
}
void build(int &t, int l, int r){
	t=++cnt;
	if (l==r){
		fa[t]=l;
		size[t]=1;
		return;
	}
	int mid=l+r>>1;
	build(ls[t],l,mid);
	build(rs[t],mid+1,r);
}
void insert(int u, int v, int x, int y, int z){
	int tv=v;
	int le=1, ri=n;
	while (le<ri){
		int mid=le+ri>>1;
		if (x<=mid){
			if (!rs[v]) rs[v]=rs[u];
			if (!ls[v] || tag[ls[v]]!=tv) tag[ls[v]=++cnt]=tv;
			v=ls[v],
			u=ls[u],
			ri=mid;
		}
		else{
			if (!ls[v]) ls[v]=ls[u];
			if (!rs[v] || tag[rs[v]]!=tv) tag[rs[v]=++cnt]=tv;
			v=rs[v],
			u=rs[u],
			le=mid+1;
		}
	}
	fa[v]=y;
	size[v]=z;
}
int main(){
	n=read();m=read();
	build(root[0],1,n);
	for (int i=1;i<=m;i++){
		int op=l[i].op=read(), x=l[i].x=read();
		if (op==1){
			int y=l[i].y=read();
			int u=find(root[i-1],x);
			int v=find(root[i-1],y);
			if (fa[u]==fa[v]) root[i]=root[i-1];
			else{
				root[i]=++cnt;
				if (size[u]>size[v]) swap(u,v);
				insert(root[i-1],root[i],fa[u],fa[v],size[u]);
				insert(root[i-1],root[i],fa[v],fa[v],size[u]+size[v]);
			}
		}
		else if (op==2){
			root[i]=root[x];
		}
		else{
			int y=l[i].y=read();
			int u=find(root[i-1],x);
			int v=find(root[i-1],y);
			printf("%d\n", fa[u]==fa[v]);
			root[i]=root[i-1];
		}
	}
	return 0;
}
