#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define INF (long long) 2147483647*1000000
#define N 100000
using namespace std;
int cnt, root, n, fa[N], r[N], l[N];
long long tot, f[N];
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
		if (l[f2]==f1) l[f2]=t;
		else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (l[f1]=r[t]) fa[l[f1]]=f1;
	r[t]=f1;
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;
		else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (r[f1]=l[t]) fa[r[f1]]=f1;
	l[t]=f1;
}
void splay(int t){
	int f1=fa[t], f2=fa[f1];
	while (f2){
		if (l[f2]==f1)
			if (l[f1]==t) zig(f1), zig(t);
			else zag(t), zig(t);
		else
			if (l[f1]==t) zig(t), zag(t);
			else zag(f1), zag(t);
		f1=fa[t];f2=fa[f1];
	}
	if (f1)
		if (l[f1]==t) zig(t);else zag(t);
	root=t;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(), j;
		long long ans=INF;
		insert(root,x);
		splay(i);
		j=l[i];
		while (j && r[j]) j=r[j];
		if (j) ans=min(ans,x-f[j]);
		j=r[i];
		while (j && l[j]) j=l[j];
		if (j) ans=min(ans,f[j]-x);
		if (ans==INF) ans=x;
		tot+=ans;
	}
	cout<<tot<<endl;
	return 0;
}
