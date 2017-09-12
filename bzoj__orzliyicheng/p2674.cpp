#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 300000
using namespace std;
int n, m, T, cnt, LSH, x[N], y[N], z[N], ans[N], lsh[N], trans[N];
int cnt_bit, f[N*60], ls[N*60], rs[N*60], root[N];
bool ques[N];
char s0[10];
struct qlz{
	int x1, y1, x2, y2, v, n;
}l[N], b1[N], b2[N];
map<int,int> mp;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int x, int y, int v){
	l[++cnt].v=v;l[cnt].x1=x;l[cnt].y1=y;
}
bool cmp(qlz a, qlz b){return a.v<b.v;}
void upd(int &t, int l, int r, int x, int y){
	if (!t) t=++cnt_bit;
	f[t]+=y;
	if (l==r) return;
	int mid=l+r>>1;
	if (x<=mid) upd(ls[t],l,mid,x,y);
	if (x>mid) upd(rs[t],mid+1,r,x,y);
}
void update(int x, int y, int z){
	for (int i=x;i<=T;i+=i&(-i))
		upd(root[i],1,T,y,z);
}
int query(int t, int l, int r, int x){
	if (!t || r<=x) return f[t];
	int mid=l+r>>1, p=query(ls[t],l,mid,x);
	if (x>mid) p+=query(rs[t],mid+1,r,x);
	return p;
}
int sum(int x, int y){
	int p=0;
	for (int i=x;i;i-=i&(-i))
		p+=query(root[i],1,T,y);
	return p;
}
void solve(int le, int ri, int L, int R){
	if (le>ri) return;
	if (L==R){
		for (int i=le;i<=ri;i++)
			if (l[i].n) ans[l[i].n]=L;
		return;
	}
	int mid=L+R>>1, ct1=0, ct2=0;
	for (int i=le;i<=ri;i++){
		if (!l[i].n){
			if (l[i].v<=mid && l[i].v>=-mid)
				update(l[i].x1,l[i].y1,l[i].v>0?1:-1),
				b1[++ct1]=l[i];
			else
				b2[++ct2]=l[i];
		}
		else{
			int k=sum(l[i].x2,l[i].y2)+sum(l[i].x1-1,l[i].y1-1)
				 -sum(l[i].x1-1,l[i].y2)-sum(l[i].x2,l[i].y1-1);
			if (k>=l[i].v)
				b1[++ct1]=l[i];
			else
				l[i].v-=k,
				b2[++ct2]=l[i];
		}
	}
	for (int i=1;i<=ct1;i++) l[le+i-1]=b1[i];
	for (int i=1;i<=ct2;i++) l[le+ct1+i-1]=b2[i];
	for (int i=le;i<=ri;i++)
		if (!l[i].n && l[i].v<=mid && l[i].v>=-mid)
			update(l[i].x1,l[i].y1,l[i].v>0?-1:1);
	solve(le,le+ct1-1,L,mid);
	solve(le+ct1,ri,mid+1,R);
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
		x[i]=read(),y[i]=read(),z[i]=read(),
		add(x[i],y[i],z[i]),
		l[cnt].n=i,
		lsh[++LSH]=x[i],
		lsh[++LSH]=y[i];
	sort(l+1,l+1+cnt,cmp);
	for (int i=1;i<=cnt;i++)
		trans[i]=l[i].v,
		z[l[i].n]=l[i].v=i,
		l[i].n=0;
	for (int i=1;i<=m;i++){
		scanf("%s", s0);
		if (s0[0]=='Q'){
			ques[i]=1;
			l[++cnt].n=i;
			l[cnt].x1=lsh[++LSH]=read();
			l[cnt].y1=lsh[++LSH]=read();
			l[cnt].x2=lsh[++LSH]=read();
			l[cnt].y2=lsh[++LSH]=read();
			l[cnt].v=read();
			if (l[cnt].x1>l[cnt].x2) swap(l[cnt].x1,l[cnt].x2);
			if (l[cnt].y1>l[cnt].y2) swap(l[cnt].y1,l[cnt].y2);
		}
		if (s0[0]=='S'){
			int u=read()+1, v=read()+1;
			if (u==v) continue;
			add(x[u],y[u],-z[u]);
			add(x[v],y[v],-z[v]);
			add(x[u],y[u],z[v]);
			add(x[v],y[v],z[u]);
			swap(z[u],z[v]);
		}
	}
	sort(lsh+1,lsh+1+LSH);
	mp[0]=++T; 
	for (int i=1;i<=LSH;i++)
		if (lsh[i]!=lsh[i-1])
			mp[lsh[i]]=++T;
	for (int i=1;i<=cnt;i++)
		l[i].x1=mp[l[i].x1],
		l[i].y1=mp[l[i].y1],
		l[i].x2=mp[l[i].x2],
		l[i].y2=mp[l[i].y2];
	solve(1,cnt,1,n+1);
	for (int i=1;i<=m;i++)
		if (ques[i])
			if (ans[i]<=n) printf("%d\n", trans[ans[i]]);
			else printf("It doesn't exist.\n");
	return 0;
}
