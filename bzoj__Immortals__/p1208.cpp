#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 200000
#define mo 1000000 
typedef long long LL;
using namespace std;
const LL INF=(LL) 999999999*9999999;
int cnt, root, n, q, fa[N], r[N], l[N];
LL f[N], ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') q=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void insert(int &t, int x){
	if (!t){
		f[t=++cnt]=x;
		return;
	}
	if (f[t]<x) insert(r[t],x);
	if (f[t]>=x) insert(l[t],x);
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
}
void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (l[f1]=r[t]) fa[l[f1]]=f1;
	r[t]=f1;
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (r[f1]=l[t]) fa[r[f1]]=f1;
	l[t]=f1;
}
void splay(int t){
	int f1=fa[t], f2=fa[f1];
	while(f2){
		if (l[f2]==f1)
			if (l[f1]==t) zig(f1), zig(t);
			else zag(t), zig(t);
		else
			if (r[f1]==t) zag(f1), zag(t);
			else zig(t), zag(t);
		f1=fa[t];f2=fa[f1];
	}
	if (f1)
		if (l[f1]==t) zig(t);else zag(t);
	root=t;
}
int query1(int t, int x){
	if (!t) return 0;
	if (f[t]>x) return query1(l[t],x);
	if (f[t]==x) return t;
	int tmp;
	if (tmp=query1(r[t],x)) return tmp;
	else return t;
}
int query2(int t, int x){
	if (!t) return 0;
	if (f[t]<=x) return query2(r[t],x);
	int tmp;
	if (tmp=query2(l[t],x)) return tmp;
	else return t;
}
void del(int t){
	splay(t);
	if (!l[t]){
		fa[root=r[t]]=0;
		return;
	}
	int j=l[t];
	while (j && r[j]) j=r[j];
	fa[root=l[t]]=0;
	if (r[j]=r[t]) fa[r[j]]=j;
}
int main(){
	for (n=read();n;n--){
		int p=read(), x=read();
		if (!root || p==q){
			if (!root) q=p;
			insert(root,x);
			splay(cnt);
		}
		else{
			int i=query1(root,x), j=query2(root,x), y;
			if (i && j)
				if (x-f[i]<=f[j]-x) y=i;else y=j;
			else y=i+j;
			ans+=abs(f[y]-x);
			del(y);
		}
	}
	cout<<ans%mo<<endl;
	return 0;
}
