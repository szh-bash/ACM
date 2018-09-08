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
#define N 200060
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
vector <int> p[N];
ll c[N], f[N], ans[N];
int n, q, de[N], x[N], dfn[N], ed[N], num[N], nu[N], nex[N], cnt, ct, BLOCK;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add (int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u, int dep){
	dfn[u]=++ct;
	num[dep]++;
	p[dep].push_back(u);
	for (int j=nex[u];j;j=nex[j])
		dfs(nu[j], dep+1);
	ed[u]=ct;
}
void dfs2(int u, int dep, int k){
	++ct;
	c[ct]=c[ct-1];
	if (dep==k) c[ct]++;
	for (int j=nex[u];j;j=nex[j]) dfs2(nu[j], dep+1, k);
}
int main(){
	cnt=n=read();q=read();
	BLOCK=sqrt(n);
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
	}
	dfs(1,1);
	for (int i=1;i<=q;i++){
		int op=read();
		if (op==1){
			int l=read()+1, y=read();
			de[i]=l;
			if (num[l]<=BLOCK){
				for (int j=0;j<num[l];j++)
					for (int k=dfn[p[l][j]];k<=n;k+=k&(-k))
						c[k]+=y;
			}
			else f[i]=y;
		}
		else{
			x[i]=read();
			for (int k=ed[x[i]];k;k-=k&(-k)) ans[i]+=c[k];
			for (int k=dfn[x[i]]-1;k;k-=k&(-k)) ans[i]-=c[k];
		}
	}
	for (int i=1;i<=n;i++)
		if (num[i]>BLOCK){
			ct=0;
			dfs2(1,1,i);
			ll ff=0;
			for (int j=1;j<=q;j++)
				if (x[j]) ans[j]+=(c[ed[x[j]]]-c[dfn[x[j]]-1])*ff;
				else ff+=f[j]*(de[j]==i);
		}
	for (int i=1;i<=q;i++)
		if (x[i]) printf("%lld\n", ans[i]);
    return 0;
}
