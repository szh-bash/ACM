#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
const int INF=2147483647;
using namespace std;
int n, m, root, s[200100], l[200100], r[200100], fa[200100], a[200100], f[200100];
int flag[200100], p[200100], sta[200100];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void down(int t){
	if (!t) return;
	if (flag[t]){
		swap(l[t],r[t]);
		flag[l[t]]^=1;
		flag[r[t]]^=1;
		flag[t]=0;
	}
	if (p[t]){
		f[t]+=p[t];
		a[t]+=p[t];
		p[l[t]]+=p[t];
		p[r[t]]+=p[t];
		p[t]=0;
	}
}
void update(int t){
	down(l[t]);down(r[t]);
	s[t]=s[l[t]]+s[r[t]]+1;
	f[t]=min(a[t],min(f[l[t]],f[r[t]]));
}
int find(int t,int p){
	down(t);
	if (s[l[t]]+1==p) return t;
	if (s[l[t]]+1<p) return find(r[t],p-s[l[t]]-1);
	return find(l[t],p);
}
void zig(int t){
	int f1=fa[t];
	fa[t]=fa[f1];
	l[f1]=r[t];
	fa[r[t]]=f1;
	r[t]=f1;
	if (fa[f1])
		if (l[fa[f1]]==f1) l[fa[f1]]=t;else r[fa[f1]]=t;
	fa[f1]=t;
	update(f1);
	update(t);
}
void zag(int t){
	int f1=fa[t];
	fa[t]=fa[f1];
	r[f1]=l[t];
	fa[l[t]]=f1;
	l[t]=f1;
	if (fa[f1])
		if (l[fa[f1]]==f1) l[fa[f1]]=t;else r[fa[f1]]=t;
	fa[f1]=t;
	update(f1);
	update(t);
}
void splay(int t){
	int top=0,j=t;
	while (j!=0) sta[++top]=j,j=fa[j];
	for (int i=top;i;i--) down(sta[i]);
	int f1=fa[t], f2=fa[fa[t]];
	while (1){
		if (!f1) break;
		if (!f2){
			if (l[f1]==t) zig(t);else zag(t);
			break;
		}
		if (l[f1]==t){
			if (l[f2]==f1) zig(f1);
			zig(t);
		}
		else{
			if (r[f2]==f1) zag(f1);
			zag(t);
		}
		f1=fa[t];f2=fa[f1];
	}
	root=t;
}
void modi(int x, int y, int z){
	splay(x);
	fa[r[x]]=0;
	splay(y);
	r[x]=y;
	fa[y]=root=x;
	p[l[y]]+=z;
}
int query(int x, int y){
	splay(x);
	fa[r[x]]=0;
	splay(y);
	r[x]=y;
	fa[y]=root=x;
	down(l[y]);
	return f[l[y]];
}
void Delete(int x){
	int y=find(root,x+2);
	splay(y);
	int son=l[y];
	down(son);
	if (r[son]==0){
		l[y]=l[son];
		fa[l[son]]=y;
		update(y);
	}
	else{
		int top=1;
		sta[1]=y;
		while (son!=0) sta[++top]=son,down(son),son=r[son];
		r[sta[top-1]]=l[sta[top]];fa[l[sta[top]]]=sta[top-1];
		top--;
		for (int i=top;i;i--) update(sta[i]);
	}
}
void insert(int x, int y){
	x=find(root,x);
	splay(x);
	int top=1;
	sta[1]=x;
	for (int j=r[x];j;j=l[j])
		down(j),sta[++top]=j;
	l[sta[top]]=y;
	fa[y]=sta[top];
	for (int j=top;j;j--) update(sta[j]);
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), s[i]=n-i+2;f[0]=f[n+1]=INF;
	for (int i=n;i;i--) r[i]=i+1, f[i]=min(a[i],f[i+1]),fa[i+1]=i;
	n+=2;
	s[n]=n;s[n-1]=1;r[n]=1;fa[1]=n;a[n]=a[n-1]=INF;f[n]=f[1];
	root=n;
	m=read();
		char ch[10];
		int x, y, z;
	while (m--){
		scanf("%s", ch);
		if (ch[0]=='A'){
			x=read();y=read()+2;z=read();
			x=find(root,x);y=find(root,y);
			modi(x,y,z);
		}
		if (ch[0]=='R' && ch[3]=='E'){
			x=read();y=read();
			x=find(root,x);y=find(root,y+2);
			splay(x);
			fa[r[x]]=0;
			splay(y);
			r[x]=y;fa[y]=root=x;
			flag[l[y]]^=1;
		}
		if (ch[0]=='R' && ch[3]=='O'){
			x=read();y=read();z=read();
			z=z%(y-x+1);
			if (!z) continue;
			int tx=x,ty=y;
			x=find(root,y-z+1);y=find(root,y+2);
			splay(x);
			fa[r[x]]=0;
			splay(y);
			r[x]=y;fa[y]=root=x;
			int tmp=l[y];fa[tmp]=0;
			l[y]=0;
			update(y);update(x);
			insert(tx,tmp);
		}
		if (ch[0]=='I'){
			x=read()+1;y=read();
			s[++n]=1;a[n]=f[n]=y;
			insert(x,n);
		}
		if (ch[0]=='D'){
			x=read();
			Delete(x);
		}
		if (ch[0]=='M'){
			x=read();y=read()+2;
			x=find(root,x);y=find(root,y);
			printf("%d\n", query(x,y)); 
		}
	}
	return 0;
	}
