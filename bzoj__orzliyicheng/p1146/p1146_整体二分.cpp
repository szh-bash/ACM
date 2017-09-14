#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 80010
#define S 2000000
using namespace std;
int n, m, T, x, gt, cnt, DFN, LSH;
int a[N], k[N], u[N], v[N], c[N], ans[N], q[N];
int fa[N][21], dep[N], trans[N*2], lsh[N*2], nex[N*3], nu[N*3], dfn[N][2];
map<int,int> mp;
char s[S+100];
struct qlz_ques{
	int k, u, v, n;
}l[N*6], b1[N*6], b2[N*6];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
void add_edge(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int father){
	dfn[u][0]=++DFN;
	fa[u][0]=father;
	for (int i=1;fa[fa[u][i-1]][i-1];i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	//cout<<DFN<<' '<<u<<endl;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (v==father) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
	dfn[u][1]=DFN+1;
}
int LCA(int u, int v){
	if (dep[u]<dep[v]) swap(u,v);
	//cout<<u<<' '<<v<<endl;
	for (int i=20;i>=0;i--)
		if (dep[fa[u][i]]>=dep[v]) u=fa[u][i];
	if (u==v) return u;
	for (int i=20;i>=0;i--)
		if (fa[u][i]!=fa[v][i]) u=fa[u][i], v=fa[v][i];
	return fa[u][0];
}
void add(int k, int u, int v){
	l[++gt].k=k, l[gt].u=u, l[gt].v=v;
}
void update(int u, int v){
	for (int i=u;i<=n;i+=i&(-i)) c[i]+=v;
}
int sum(int u){
	int p=0;
	for (int i=dfn[u][0];i;i-=i&(-i)) p+=c[i];
	return p;
}
void solve(int le, int ri, int L, int R){
	//cout<<le<<' '<<ri<<' '<<L<<' '<<R<<endl;
	if (le>ri) return;
	if (L==R){
		for (int i=le;i<=ri;i++)
			if (l[i].n) ans[l[i].n]=L;
		return;
	}
	int mid=L+R>>1, ct1=0, ct2=0;
	for (int i=le;i<=ri;i++){
		if (l[i].n){
			int u=l[i].u, v=l[i].v, lca=LCA(u,v),k=sum(u)+sum(v)-sum(lca)-sum(fa[lca][0]);
			if (k>=l[i].k)
				b2[++ct2]=l[i];
			else
				l[i].k-=k,
				b1[++ct1]=l[i];
			
		}
		else
			if (l[i].v>mid || l[i].v<-mid)
				b2[++ct2]=l[i],
				update(l[i].u,l[i].v>0?1:-1);
			else
				b1[++ct1]=l[i];
	}
	for (int i=1;i<=ct1;i++) l[le+i-1]=b1[i];
	for (int i=1;i<=ct2;i++) l[le+ct1+i-1]=b2[i];
	for (int i=le;i<=ri;i++)
		if (!l[i].n && (l[i].v>mid || l[i].v<-mid))
			update(l[i].u,l[i].v>0?-1:1);
	solve(le,le+ct1-1,L,mid);
	solve(le+ct1,ri,mid+1,R);
}
int main(){
	freopen("network10.in","r",stdin);
	freopen("整体二分.out","w",stdout);
//read
	fread(s,1,S,stdin);
	cnt=n=read();m=read();
	for (int i=1;i<=n;i++)
		lsh[++LSH]=a[i]=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	for (int i=1;i<=m;i++)
		k[i]=read(),
		u[i]=read(),
		v[i]=read(),
		(!k[i]?lsh[++LSH]=v[i]:0);
//lsh
	dfs(dep[1]=1,0);
	sort(lsh+1,lsh+1+LSH);
	trans[mp[0]=++T]=0;
	for (int i=1;i<=LSH;i++)
		if (lsh[i]!=lsh[i-1]) trans[mp[lsh[i]]=++T]=lsh[i];
	for (int i=1;i<=n;i++)
		add(0,dfn[i][0],mp[a[i]]),
		add(0,dfn[i][1],-mp[a[i]]);
	for (int i=1;i<=m;i++)
		if (k[i])
			add(k[i],u[i],v[i]),
			l[gt].n=i,
			q[i]=1;
		else
			add(0,dfn[u[i]][0],-mp[a[u[i]]]),
			add(0,dfn[u[i]][1],mp[a[u[i]]]),
			add(0,dfn[u[i]][0],mp[a[u[i]]=v[i]]),
			add(0,dfn[u[i]][1],-mp[v[i]]);
//work
	solve(1,gt,0,T);
	//int tot=0;
	for (int i=1;i<=m;i++)
		if(q[i]){
			//tot++;
			if (ans[i]) printf("%d\n", trans[ans[i]]);
			else printf("invalid request!\n");
		}
	//cout<<n<<' '<<m<<' '<<tot<<' '<<m-tot<<endl;
	return 0;
}
