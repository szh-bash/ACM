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
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
#define DATA 32*1024*1024
int idx, index;
char s[DATA], sout[DATA];
int read(){
    int p=0, q=1;
    while (!num(s[idx])) (s[idx++]=='-'?q=-1:0);
    while (num(s[idx])) p=p*10+s[idx++]-'0';
    return p*q;
}
#define N 100005
#define Q 100005
#define M N*3
#define BIT 25 
int n, m, cnt, col[N], val[N], nex[M], num[M], nu[M];
int in[N], ot[N], son[N], dst[N], ori[N], esc[N];
ll ans[Q];
inline void add(int &u, int &v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int ct;
struct node{
	int m, n, c, v, y;
}l[(N+Q)*2];
inline void insert(int m, int &n, int &col, int &val, int y){
	l[++ct].m=m;
	l[ct].n=n;
	l[ct].c=col;
	l[ct].v=val;
	l[ct].y=y;
}
inline bool cmp (node &a, node &b){
	if (a.c<b.c) return 1;
	if (a.c>b.c) return 0;
	return a.m<b.m;
}
void dfs(int u, int fa){
	in[u]=++cnt;
	son[u]=0;
	dst[u]=dst[fa]+1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==fa) continue;
		dfs(v,u);
		son[u]+=son[v]+1;
	}
	ot[u]=cnt;
}
int d, co[2][N*2], cf[2][N*2];
inline int sum(int x, int c[]){
	int res=0;
	for (;x;x-=x&(-x)) res+=c[x];
	return res;
}
inline void upd(int x, int y, int c[]){
	for (;x<=cnt;x+=x&(-x)) c[x]+=y;
}
inline void print(ll x){
	int base=index;
	if (!x) sout[index++]='0';
	while (x){
		sout[index++]=x%10+'0';
		x/=10;
	}
	for (int i=base;i-base+1<=(index-base)/2;i++) swap(sout[i],sout[index-(i-base+1)]);
	sout[index++]='\n';
}
int tot0, tot1;
void solve(){
	int ma=0, bit=0;
	cnt=n=read();ct=0;
	for (int i=1;i<=n;i++) col[i]=read(), nex[i]=0;
	for (int i=1;i<=n;i++) val[i]=read(), ma=max(ma, val[i]);
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	for (int i=1;i<=n;i++) insert(0,i,col[i],val[i],1);
	m=read();
	for (int i=1;i<=m;i++){
		int op=read(), x=read(), y=read();
		insert(i,x,col[x],val[x],-1);
		if (op==1)
			val[x]=y,
			ma=max(ma, val[x]);
		else col[x]=y;
		insert(i,x,col[x],val[x],1);
	}
	for (int i=1;i<=n;i++) insert(m+1,i,col[i],val[i],-1);
	for (bit=BIT-1;bit>=0 && !((1<<bit)&ma);bit--);bit++;
	sort(l+1,l+1+ct,cmp);
	dfs(1,cnt=0);
	for (int i=0;i<=m;i++) ans[i]=0;
	for (d=0;d<bit;d++)
		for (int j=1;j<=ct;j++){
			int y=l[j].y, tn=l[j].n, fv=(l[j].v&(1<<d))>0;
			if (fv)
				ans[l[j].m]+=1ll*(tot0-(sum(ot[tn],co[0])-sum(in[tn],co[0])+sum(in[tn],cf[0])))
								*(1<<d)*y,
				tot1+=y;
			else
				ans[l[j].m]+=1ll*(tot1-(sum(ot[tn],co[1])-sum(in[tn],co[1])+sum(in[tn],cf[1])))
								*(1<<d)*y, 
				tot0+=y;
			upd(in[tn],y,co[fv]);
			upd(in[tn],y,cf[fv]);
			upd(ot[tn]+1,-y,cf[fv]);
		}
	print(ans[0]);
	for (int i=1;i<=m;i++) print(ans[i]+=ans[i-1]);
}
int main(){
	freopen("c.data","r",stdin);
	freopen("c.ans","w",stdout);
	fread(s,1,DATA,stdin);
	for (int _=read();_;_--) solve();
	fwrite(sout,1,strlen(sout),stdout);
    return 0;
}
