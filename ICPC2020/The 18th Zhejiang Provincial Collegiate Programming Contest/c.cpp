#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 15
int n=8;
int x[N], y[N], z[N], flag[N], a[N], b[N];
inline int sqr(int x){return x*x;}
inline int dis(int u, int v){
	return sqr(x[u]-x[v])+sqr(y[u]-y[v])+sqr(z[u]-z[v]);
}
inline int dot_p(int w, int u, int v){
	return (x[u]-x[w])*(x[v]-x[w])+(y[u]-y[w])*(y[v]-y[w])+(z[u]-z[w])*(z[v]-z[w]);
}
int x1, y1, z1, x2, y2, z2;
inline bool para(int u0, int u1, int v0, int v1){
	x1 = x[u1]-x[u0];
	y1 = y[u1]-y[u0];
	z1 = z[u1]-z[u0];
	x2 = x[v1]-x[v0];
	y2 = y[v1]-y[v0];
	z2 = z[v1]-z[v0];
	if (x1*x2==0 && x1+x2) return 0;
	if (y1*y2==0 && y1+y2) return 0;
	if (z1*z2==0 && z1+z2) return 0;
	if (x1){
		if (y1 && x1*y2!=x2*y1) return 0;
		if (z1 && x1*z2!=x2*z1) return 0;
		return 1;
	}
	else{
		if (y1 && z1 && y1*z2!=z1*y2) return 0;
		return 1;
	}
}

inline bool check(int st, int ed){
	int cta=0, ctb=0;
	for (int i=1;i<=8;i++)
		if (!flag[i]) a[++cta]=i;
		else if (flag[i]==1) b[++ctb]=i;
	int tmp = dis(st,a[1]);
	if (tmp==0) return 0;
	// cout<<tmp<<endl;
	for (int i=1;i<=3;i++)
		if (dis(a[i],st) !=tmp || dis(b[i],ed)!=tmp) return 0;
	for (int i=1;i<3;i++)
		for (int j=i+1;j<=3;j++)
			if (dot_p(st,a[i],a[j]) || dot_p(ed,b[i],b[j])) return 0;
	for (int i=1;i<=3;i++)
		for (int j=1;j<=3;j++)
		if (i!=j)
			for (int k=1;k<=3;k++)
			if (i!=k && j!=k){
				if (!para(st,a[1],ed,b[i]) || !para(st,a[2],ed,b[j]) || !para(st,a[3],ed,b[k]))
					continue;
				if (dis(a[1],b[j])!=tmp || dis(a[1],b[k])!=tmp ||
					dis(a[2],b[i])!=tmp || dis(a[2],b[k])!=tmp ||
					dis(a[3],b[i])!=tmp || dis(a[3],b[j])!=tmp)
					return 0;
				return 1;
			}
	return 0;
}
inline bool dfs(int u, int t, int st, int ed){
	if (t==3) {return check(st, ed);}
	if (u>n) return 0;
	if (!flag[u]){
		flag[u]=1;
		if (dfs(u+1,t+1,st,ed)) return 1;
		flag[u]=0;
		return 0;
	}
	return dfs(u+1,t,st,ed);
}
inline bool work(int u, int v){
	if (u == v) return 0;
	flag[u]=2, flag[v]=3;
	// cout<<dfs(1,0,u,v)<<endl;
	if (dfs(1,0,u,v)) return 1;
	flag[u]=flag[v]=0;
	return 0;
}
void solve(){
	for (int i=1;i<=n;i++)
		x[i]=read(), y[i]=read(), z[i]=read();
	for (int i=1;i<=n;i++) flag[i]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (work(i,j)){
				// cout<<i<<' '<<j<<endl;
				puts("YES");
				return;
			}
	puts("NO");
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
