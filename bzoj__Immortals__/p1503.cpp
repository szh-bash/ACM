#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 200000
#define mo 1000000 
typedef long long LL;
using namespace std;
int ans, cnt, root, n, m, fa[N], r[N], l[N], f[N], p[N], size[N], list[N];
char s[1];
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
void pushdown(int t){
	if (!p[t]) return;
	if (l[t]) p[l[t]]+=p[t];
	if (r[t]) p[r[t]]+=p[t];
	f[t]+=p[t];
	p[t]=0;
}
void pushup(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	size[t]=size[l[t]]+size[r[t]]+1;	
}
void insert(int &t, int x){
	if (!t){
		f[t=++cnt]=x;
		size[t]=1;
		return;
	}
	pushdown(t);
	if (f[t]<=x) insert(r[t],x);
	if (f[t]>x) insert(l[t],x);
	pushup(t);
}
void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (l[f1]=r[t]) fa[l[f1]]=f1;
	r[t]=f1;
	pushup(f1);
	pushup(t);
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (r[f1]=l[t]) fa[r[f1]]=f1;
	l[t]=f1;
	pushup(f1);
	pushup(t);
}
void splay(int t){
	int f1=fa[t], f2=fa[f1];
	int ri=1;
	list[1]=t;
	for (int i=1;fa[list[i]];i++) list[++ri]=fa[list[i]];
	for (int i=ri;i;i--) pushdown(list[i]);
	while (f2){
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
int find(int t){
	if (!t) return 0;
	pushdown(t);
	if (f[t]>=m) return find(l[t]);
	int tmp=find(r[t]);
	if (!tmp) tmp=t;
	return tmp;
}
void del(int t){
	if (!t) return;
	splay(t);
	if (root=r[t]) fa[r[t]]=0;
	ans+=size[t]-size[r[t]];
}
int query(int t, int k){
	pushdown(t);
	if (size[r[t]]+1==k) return f[t];
	if (size[r[t]]+1<k) return query(l[t],k-size[r[t]]-1);
	return query(r[t],k);
}
int main(){
	n=read();
	for (m=read();n;n--){
		scanf("%s", s);
		int k=read();
		if (s[0]=='I'){
			if (k<m) continue;
			insert(root,k);
			splay(cnt);
		}
		if (s[0]=='A'){
			if (!root) continue;
			p[root]+=k;
		}
		if (s[0]=='S'){
			if (!root) continue;
			p[root]-=k;
			del(find(root));
		}
		if (s[0]=='F'){
			printf("%d\n", size[root]>=k?query(root,k):-1);
		}
	}
	cout<<ans<<endl;
	return 0;
}
