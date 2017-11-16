#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 300000
#define M 1500000
#define INF (double)99999999*99999
#define eps 1e-4
using namespace std;
int mx, n, m, L, R, cnt, sum, root, posL, head, tail, check_flag;
int next[M], nu[M], va[M];
int dep[N], a[N], to[N], q[N], vis[N], flag[N], ff[N], son[N], l[N];
double  g[N], f[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void getroot(int t, int fa){
	son[t]=1;
	ff[t]=0;
	for (int j=next[t];j;j=next[j]){
		int v=nu[j];
		if (v==fa || vis[v]) continue;
		getroot(v,t);
		son[t]+=son[v];
		ff[t]=max(ff[t],son[v]);
	}
	ff[t]=max(ff[t],sum-son[t]);
	if (ff[t]<ff[root]) root=t;
}
void clear(int t, int fa, int depth){
	flag[t]=0;
	f[dep[t]=depth]=-INF;
	son[t]=1;
	for (int j=next[t];j;j=next[j]){
		int v=nu[j];
		if (v==fa || vis[v])  continue;
		clear(v,t,depth+1);
		son[t]+=son[v];
		dep[t]=max(dep[t],dep[v]);
	}
}
void calc(int ll, int rr, double x, int dep){
	if (ll>rr) return;
	int ri=rr;
	while (posL && posL+dep>=L){
		while (tail>=head && f[q[tail]]<f[posL]) tail--;
		q[++tail]=posL--;
	}
	while (head<=tail && q[head]+dep>R) head++;
	for (int i=ll;i<=rr;i++){
		int t=l[i];
		flag[t]=1;
		if (head<=tail && g[t]+f[q[head]]>=0 || dep>=L && dep<=R && g[t]>=0){
			check_flag=1;
			return;
		}
		for (int j=next[t];j;j=next[j]){
			int v=nu[j];
			if (vis[v] || flag[v]) continue;
			g[v]=g[t]+va[j]-x;
			l[++ri]=v;
		}
	}
	calc(rr+1,ri,x,dep+1);
	if (check_flag) return;
	for (int i=ll;i<=rr;i++) f[dep]=max(f[dep],g[l[i]]);
}
bool cmp(int x, int y){return dep[x]<dep[y];}
void solve(int t, int la, double x){
	clear(t,0,0);
	if (dep[t]*2<L) return;
	flag[t]=vis[t]=1;
	mx=posL=0;
	int ra=la;
	for (int j=next[t];j;j=next[j]){
		int v=nu[j];
		if (vis[v]) continue;
		a[ra++]=v;
		to[v]=va[j];
	}
	if (la<ra) sort(a+la,a+ra,cmp);
	for (int i=la;i<ra;i++){
		int v=a[i];
		l[1]=v;
		g[v]=to[v]-x;
		head=1;tail=0;
		calc(1,1,x,1);
		posL=mx=max(mx,dep[v]);
		if (check_flag) return;
	}
	for (int i=la;i<ra;i++){
		int v=a[i];
		root=0;sum=son[v];
		getroot(v,0);
		solve(root,ra,x);
	}
}
bool check(double x){
	check_flag=0;
	for (int i=1;i<=n;i++) vis[i]=0;
	sum=ff[root=0]=n;
	getroot(1,0);
	solve(root,1,x);
	return check_flag;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cnt=n=read();
	L=read();R=read(); 
	double le=0, ri=0, mid;
	for (int i=1;i<n;i++){
		int u=read(), v=read(), w=read();
		ri=max(ri,double(w));
		add(u,v,w);
		add(v,u,w);
	}
	while (ri-le>eps){
		mid=(le+ri)/2;
		if (check(mid)) le=mid;
		else ri=mid;
	}
	printf("%.3lf\n", le);
	return 0;
}
