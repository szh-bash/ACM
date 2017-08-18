#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 110000
typedef unsigned int Uint;
using namespace std;
const int base=2333333;
int n, root, l[N], r[N], fa[N], size[N];
char s[N];
Uint f[N], q[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void update(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	f[t]=f[l[t]]*q[size[r[t]]+1]+s[t]*q[size[r[t]]]+f[r[t]];
	size[t]=size[l[t]]+size[r[t]]+1;
}
int build(int le, int ri){
	if (le>ri) return 0;
	int mid=le+ri>>1;
	l[mid]=build(le,mid-1);
	r[mid]=build(mid+1,ri);
	update(mid);
	return mid;
}
void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (l[f1]=r[t]) fa[l[f1]]=f1;
	r[t]=f1;
	update(f1);
	update(t);
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[fa[f1]=t]=f2;
	if (r[f1]=l[t]) fa[r[f1]]=f1;
	l[t]=f1;
	update(f1);
	update(t);
}
void splay(int t){
	int f1=fa[t], f2=fa[f1];
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
int find(int t, int k){
	if (k>n) return 0;
	while (size[l[t]]+1!=k){
		if (size[l[t]]+1<k)
			k-=size[l[t]]+1, t=r[t];
		else
			t=l[t];
	}
	return t;
}
void insert(int &t, int k, char ch){
	if (!t){
		t=++n;
		s[t]=f[t]=ch;
		size[t]=1;
		return;
	}
	if (size[l[t]]+1<=k) insert(r[t],k-size[l[t]]-1,ch);
	else insert(l[t],k,ch);
	update(t);
}
int check(int l1, int l2, int r1, int r2){
	if (!r1 || !r2) return 0;
	Uint tp1, tp2;
	splay(l1);
	fa[r[l1]]=0;
	splay(r1);
	tp1=f[l[r1]];
	update(root=fa[r[l1]=r1]=l1);
	splay(l2);
	fa[r[l2]]=0;
	splay(r2);
	tp2=f[l[r2]];
	update(root=fa[r[l2]=r2]=l2);
	return tp1==tp2;
}
int main(){
	q[0]=1;
	for (int i=1;i<=N-100;i++) q[i]=q[i-1]*base;
	scanf("%s", s+2);
	s[0]=s[1]='0';
	s[n=strlen(s)]='0';
	root=build(1,n);
	for (int m=read();m;m--){
		scanf("%s", s);
		int x=read(), y;
		char d[2];
		if (s[0]=='Q'){
			y=read();
			int le=0, ri=n+1;
			while (le<ri-1){
				int mid=le+ri>>1;
				if (check(find(root,x),find(root,y),find(root,x+mid+1), find(root,y+mid+1))) le=mid;else ri=mid;
			}
			printf("%d\n", le);
		}
		if (s[0]=='R'){
			scanf("%s", d);
			y=find(root,x+1);
			splay(y);
			f[y]=f[l[y]]*q[size[r[y]]+1]+(s[y]=d[0])*q[size[r[y]]]+f[r[y]];
		}
		if (s[0]=='I'){
			scanf("%s", d);
			insert(root,x+1,d[0]);
			splay(n);
		}
	}
	return 0;
}
