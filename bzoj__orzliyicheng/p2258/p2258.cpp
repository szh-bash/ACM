#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 100000009
using namespace std;
int n, ls, size[81000], l[81000], r[81000], fa[81000], a[81000], root;
long long f[81000];
char s[81001];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9'){
		p=p*10+ch-'0';
		ch=getchar();
	}
	return p;
}
long long power(int b, long long a){
	long long c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b/=2;
	}
	return c;
}
void update(int t){
	f[t]=a[t];
	size[t]=1;
	if (r[t]>-1) f[t]=(f[t]+f[r[t]]*131)%mo, fa[r[t]]=t, size[t]+=size[r[t]];
	if (l[t]>-1) f[t]=(f[t]*power(size[l[t]],131)%mo+f[l[t]])%mo, fa[l[t]]=t, size[t]+=size[l[t]];
}
void add(int &t, int p, int x){
	if (t==-1){t=x;return;}
	int tmp=0;
	if (l[t]>-1) tmp=size[l[t]];
	if (p>=tmp+1) add(r[t],p-tmp-1,x);
	if (p<tmp+1) add(l[t],p,x);
	update(t);
}
void zig(int t){
	int f1=fa[t];
	l[f1]=r[t];
	if (r[t]>-1) fa[r[t]]=f1;
	r[t]=f1;
	fa[t]=fa[f1];
	if (fa[f1]>-1)
		if (l[fa[f1]]==f1) l[fa[f1]]=t;else r[fa[f1]]=t;
	fa[f1]=t;
	update(f1);
	update(t);
}
void zag(int t){
	int f1=fa[t];
	r[f1]=l[t];
	if (l[t]>-1) fa[l[t]]=f1;
	l[t]=f1;
	fa[t]=fa[f1];
	if (fa[f1]>-1)
		if (l[fa[f1]]==f1) l[fa[f1]]=t;else r[fa[f1]]=t;
	fa[f1]=t;
	update(f1);
	update(t);
}
void splay(int t){
	int f1,f2=-1;
	f1=fa[t];if (f1>-1)f2=fa[f1];
	while (1){
		f1=fa[t];
		if (f1==-1) break;
		f2=fa[f1];
		if (f2==-1){
			if (l[f1]==t) zig(t);else zag(t);
			break;
		}
		if (l[f1]==t) {
			if (l[f2]==f1) zig(f1);
			zig(t);
		}
		else{
			if (r[f2]==f1) zag(f1);
			zag(t);
		}
	}
	update(t);
	root=t;
}
int find(int t, int x){
	int tmp=0;
	if (l[t]>-1) tmp=size[l[t]];
	if (tmp+1==x) return t;
	if (tmp+1>x) return find(l[t],x);else return find(r[t],x-tmp-1);
}
long long func(int t, int x){
	if (x==1) {return a[t];}
	splay(t);
	fa[r[t]]=-1;
	int f1=find(r[t],x-1);
	splay(f1);
	fa[r[t]=f1]=root=t;
	if (x==2) return a[t]+a[f1]*131;
	return (f[l[f1]]*131+power(size[l[f1]]+1,131)*a[f1]%mo+a[t])%mo;
}
int fun2(int t){
	splay(t);
	if (r[t]>-1) return size[r[t]]+1;
	return 1;
}
void work(int l1, int l2){
	int le=0,ri=min(fun2(--l1),fun2(--l2))+1;
	while (le<ri-1){
		int mid=ri+le>>1;
		if (func(l1,mid)==func(l2,mid)) le=mid;else ri=mid;
	}
	cout<<le<<endl;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	memset(l,-1,sizeof(l));
	memset(r,-1,sizeof(r));
	memset(fa,-1,sizeof(fa));
	scanf("%s", s);ls=strlen(s);
	f[0]=a[0]=s[0];
	size[0]=1;
	for (int i=1;i<ls;i++){f[i]=a[i]=s[i];add(root,i,i);splay(i);}
	n=read();
	splay(ls/2); 
	for (int i=1;i<=n;i++){
		char ch=getchar();int x, y;
		if (ch=='Q'){
			x=read();y=read();
			work(x,y);
		}
		else{
			getchar();
			ch=getchar();
			x=read();
			if (x>ls) x=ls;else x--;
			f[ls]=a[ls]=ch;
			add(root,x,ls);
			splay(ls);
			ls++;
		}
	}
	return 0;
}
