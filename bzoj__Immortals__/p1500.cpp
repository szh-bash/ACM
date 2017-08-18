#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 500100
#define M 4000010
#define INF 999999999
typedef long long LL;
using namespace std;
int root, n, cnt, m, stack[N], list[N/10], fa[N], l[N], r[N], size[N], f[N][3], g[N], a[N], c[M];
bool flag[N], flag2[N];
LL sum[N];
char s[20];
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
void update(int t){
	if (l[t]) fa[l[t]]=t;
	if (r[t]) fa[r[t]]=t;
	size[t]=size[l[t]]+size[r[t]]+1;
	sum[t]=sum[l[t]]+sum[r[t]]+a[t];
	f[t][0]=max(f[l[t]][0],(int)sum[l[t]]+f[r[t]][0]+a[t]);
	f[t][1]=max(f[r[t]][1],(int)sum[r[t]]+f[l[t]][1]+a[t]);
	f[t][2]=f[l[t]][1]+f[r[t]][0]+a[t];
	f[t][2]=max(f[t][2],max(f[l[t]][2],f[r[t]][2]));
}
void pushdown(int t){
	if (flag[t]){
		flag[l[t]]^=1;
		flag[r[t]]^=1;
		swap(l[t],r[t]);
		swap(f[l[t]][0],f[l[t]][1]);
		swap(f[r[t]][0],f[r[t]][1]);
		flag[t]=0;
	}
	if (flag2[t]){
		if (l[t]){
			sum[l[t]]=g[t]*size[l[t]];
			if (g[t]>0)
				f[l[t]][0]=f[l[t]][1]=f[l[t]][2]=sum[l[t]];
			else
				f[l[t]][0]=f[l[t]][1]=0, f[l[t]][2]=g[t];
			g[l[t]]=a[l[t]]=g[t];
			flag2[l[t]]=1;
		}
		if (r[t]){
			sum[r[t]]=g[t]*size[r[t]];
			if (g[t]>0)
				f[r[t]][0]=f[r[t]][1]=f[r[t]][2]=sum[r[t]];
			else
				f[r[t]][0]=f[r[t]][1]=0, f[r[t]][2]=g[t];
			g[r[t]]=a[r[t]]=g[t];
			flag2[r[t]]=1;
		}
		flag2[t]=g[t]=0;
	}
}
int build(int le, int ri){
	if (le>ri) return 0;
	int mid=le+ri>>1, t=stack[cnt--];
	a[t]=c[mid];
	flag[t]=flag2[t]=g[t]=fa[t]=0;
	l[t]=build(le,mid-1);
	r[t]=build(mid+1,ri);
	update(t);
	return t;
}
void insert(int &t, int k, int p){
	if (!t){
		if (!size[t=p]){
			size[t]=1;
			f[t][0]=f[t][1]=a[t]>0?a[t]:0;
			f[t][2]=sum[t]=a[t];
		}
		return;
	}
	pushdown(t);
	if (size[l[t]]+1<=k) insert(r[t],k-size[l[t]]-1,p);
	else insert(l[t],k,p);
	update(t);
}
void zig(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[t]=f2;
	l[f1]=r[t];
	r[t]=f1;
	update(f1);
	update(t);
}
void zag(int t){
	int f1=fa[t], f2=fa[f1];
	if (f2)
		if (l[f2]==f1) l[f2]=t;else r[f2]=t;
	fa[t]=f2;
	r[f1]=l[t];
	l[t]=f1;
	update(f1);
	update(t);
}
void splay(int t){
	int ri=1;
	list[1]=t;
	for (int i=1;fa[list[i]];i++) list[++ri]=fa[list[i]];
	for (int i=ri;i;i--) pushdown(list[i]);
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
	pushdown(t);
	while (size[l[t]]+1!=k){
		if (size[l[t]]+1<k)
			k-=size[l[t]]+1, t=r[t];
		else
			t=l[t];
		pushdown(t);
	}
	return t;
}
void release(int t){
	if (!t) return;
	release(l[t]);
	release(r[t]);
	stack[++cnt]=t;
}
void del(int x, int y){
	splay(x);
	fa[r[x]]=0;
	splay(y);
	int tmp=l[y];
	l[r[root=x]=y]=0;
	update(y);
	update(x);
	release(tmp);
}
void modify(int x, int y, int z){
	splay(x);
	fa[r[x]]=0;
	splay(y);
	r[root=x]=y;
	flag2[l[y]]=1;
	g[l[y]]=a[l[y]]=z;
	sum[l[y]]=size[l[y]]*z;
	if (z>0)
		f[l[y]][0]=f[l[y]][1]=f[l[y]][2]=sum[l[y]];
	else
		f[l[y]][0]=f[l[y]][1]=0, f[l[y]][2]=z;
	update(y);
	update(x);
}
void reverse(int x, int y){
	splay(x);
	fa[r[x]]=0;
	splay(y);
	fa[r[root=x]=y]=x;
	flag[l[y]]^=1;
    swap(f[l[y]][0],f[l[y]][1]);
    update(y);
    update(x);
}
void calc(int x, int y){
	splay(x);
	fa[r[x]]=0;
	splay(y);
	fa[r[root=x]=y]=x;
	printf("%d\n", sum[l[y]]);
}
void print(int t){
	if (!t) return;
	pushdown(t);
	print(l[t]);
	printf("%d ", a[t]);
	print(r[t]);
}
int main(){
	n=read();m=read();
	cnt=N-1;
	for (int i=1;i<=cnt;i++) stack[i]=i;
	for (int i=1;i<=n;i++) c[i]=read();
	f[0][2]=-INF;
	root=build(1,n);
	a[stack[cnt--]]=-INF;
	insert(root,0,stack[cnt+1]);
	a[stack[cnt--]]=-INF;
	insert(root,n+1,stack[cnt+1]);
	for (;m;m--){
		scanf("%s", s);
		if (s[0]=='I'){
			int pos=read(), tot=read(), n2=n+tot, root2;
			for (int i=n+1;i<=n2;i++) c[i]=read();
			root2=build(n+1,n2);
			insert(root,pos+1,root2);
			splay(root2);
			n=n2;
		}
		if (s[0]=='D'){
			int x=read(), y=read()+x+1;
			x=find(root,x);
			y=find(root,y);
			del(x,y);
		}
		if (s[2]=='K'){
			int x=read(), y=read()+x+1, z=read();
			x=find(root,x);
			y=find(root,y);
			modify(x,y,z);
		}
		if (s[0]=='R'){
			int x=read(), y=read()+x+1;
			x=find(root,x);
			y=find(root,y);
			reverse(x,y);
		}
		if (s[0]=='G'){
			int x=read(), y=read()+x+1;
			x=find(root,x);
			y=find(root,y);
			calc(x,y);
		}
		if (s[2]=='X'){
			printf("%d\n", f[root][2]);
		}
	}
	return 0;
}
