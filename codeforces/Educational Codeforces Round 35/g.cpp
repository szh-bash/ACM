#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	l[f1]=r[t];
	r[t]=f1;
	if (l[f1]) fa[l[f1]]=f1;
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	r[f1]=l[t];
	l[t]=f1;
	if (r[f1]) fa[r[f1]]=f1;
}
void splay(int v, int t){
	int f1=fa[t], f2=fa[f1];
	while (f2){
		if (l[f2]==f1)
			if (l[f1]==t) zig(f1), zig(t);
			else zag(t), zig(t);
		else
			if (r[f1]==t) zag(f1), zag(t);
			else zig(t), zag(t);
		f1=fa[t], f2=fa[f1];
	}
	if (f1)
		if (le[f1]==t) zig(t);else zag(t);
	root[v]=t;
}
void add(int &t, int x){
	if (!root[t]){
		cnt[t]=x;
		root[t]=x;
		return;
	}
	int y=root[t];
	while (y!=x){
		if (x>y){
			if (!ri[y]) ri[y]=x, fa[x]=y;
			y=ri[y];
		}
		else{
			if (!le[y]) le[y]=x, fa[x]=y;
			y=le[y];
		}
	}
	splay(t, x);
}
void uni(int x, int y, int l, int r){
	int l1=find(x,l-1), r1=find(x,r+1), l2=find(y,l-1), r2=find(y,r+1);
	splay(
}
int main(){
	n=read();
	for (int i=1;i<=100;i++)
		add(i,1),
		add(i,102);
	for (int i=1;i<=n;i++){
		int x=read();
		add(x,i+1);
	}
	for (int q=read();q;q--){
		int l=read(), r=read(), x=read(), y=read();
		uni(x,y,l+1,r+1);
	}
	return 0;
}
