#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define M 100005
#define N M
#define inf 101
using namespace std;
int n, m, K;
int fa[N];
int u[M], v[M], w[M], c[M];
int read(){
	int x=0,p=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=='-'?p=-1:0;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*p;
}
struct edge{
	int u, v, w, c;
}q[M];
bool cmp(const edge &a, const edge &b){
	if (a.w==b.w) return a.c<b.c;
	return a.w<b.w;
}
int father(int &x){return fa[x]==x?x:fa[x]=father(fa[x]);}
int ans, res, ct;
bool check(int &x){
	for (int i=1;i<=m;i++){
		q[i].u=u[i];
		q[i].v=v[i];
		q[i].c=c[i];
		q[i].w=w[i];
		if (!c[i]) q[i].w-=x;
	}
	sort(q+1,q+1+m,cmp);
	for (int i=1;i<=n;i++) fa[i]=i; 
	ct=res=0;
	for (int i=1, tot=n-1;i<=m;i++){
		int u=q[i].u, v=q[i].v;
		int pu=father(u), pv=father(v); 
		if (pu!=pv){
			fa[pu]=pv;
			res+=q[i].w;
			if (!q[i].c) ++ct;
			if (!--tot) break;
		}
	}
	return ct<K;
}
void wqs(){
	int le=-inf, ri=inf;
	while (le!=ri){
		int mid=le+ri>>1;
		if (check(mid)) le=mid+1;else ri=mid-1, ans=res+K*mid;
	}
	cout<<ans<<endl;
}
int main(){
	n=read();m=read();K=read();
	for (int i=1;i<=m;i++) 
		u[i]=read()+1,
		v[i]=read()+1,
		w[i]=read(),
		c[i]=read();
	wqs();
	return 0;
}
