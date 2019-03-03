#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 2000
#define M 2000
typedef long long ll;
using namespace std;
char s[N][M];
int n, m, cnt, flag[N+M], g[N+M], fa[N+M], nex[(N+M)*1000], nu[(N+M)*1000], d[N+M], l[N+M], f[N+M];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
	d[v]++;
}
void dfs(int u){
	f[u]=g[u];
	for (int j=nex[u];j;j=nex[j]){
		int v=fa[nu[j]];
		if (!f[v]) dfs(v);
		f[u]=min(f[u],f[v]);
	}
}
int main(){
	n=read();m=read();
	cnt=n+m;
	for (int i=1;i<=n+m;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		scanf("%s", s[i]+1);
		for (int j=1;j<=m;j++)
			if (s[i][j]=='=') fa[father(j+n)]=father(i);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++)
			if (s[i][j]=='<') add(father(j+n),father(i));
			else if (s[i][j]=='>') add(father(i),father(j+n));
	}
	int le=1, ri=0, ans=0, ct=n+m;
	for (int i=1;i<=n+m;i++) ans+=father(i)==i;
	for (int i=1;i<=n+m;i++)
		if (!d[fa[i]] && !flag[fa[i]]) l[++ri]=fa[i], flag[fa[i]]=-1, ans--;
while (le<=ri){
	int rr=ri;
	while (le<=rr){
		int u=l[le++];
		g[u]=ct;
		for (int j=nex[u];j;j=nex[j]){
			int v=fa[nu[j]];
			//if (flag[v]==u) continue;
			//flag[v]=u;
			if (--d[v]==0) l[++ri]=v, ans--;
		}
	}
	ct--;
}
	if (ans){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	for (int i=1;i<=n+m;i++)
		if (!f[fa[i]]) dfs(fa[i]);
	for (int i=1;i<=n+m;i++) printf("%d%s", g[fa[i]]-f[fa[i]]+1, (i==n || i==n+m)?"\n":" ");
	return 0;
}
