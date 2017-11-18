#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 1000000
typedef long long ll;
using namespace std;
int n, m, q, x[N], y[N], w[N], fa[N], list[N], cnt, ans[N], f[N], sum[N];
struct edge{
	int x, y, w, n, q;
}l[N], l2[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(edge a, edge b){return a.w<b.w;}
bool cmp2(edge a, edge b){
	if (a.w<b.w) return 1;
	if (a.w>b.w) return 0;
	return a.q<b.q;
}
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
int getfa(int x){return fa[x]==x?x:getfa(fa[x]);}
int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++)
		l[i].x=x[i]=read(),
		l[i].y=y[i]=read(),
		l[i].w=w[i]=read(),
		l[i].n=i;
	q=read();
	for (int i=1;i<=q;i++){
		int k=read();
		for (int j=1;j<=k;j++){
			int u=read();
			l2[++cnt].x=x[u];
			l2[cnt].y=y[u];
			l2[cnt].w=w[u];
			l2[cnt].n=u;
			l2[cnt].q=i;
		}
	}
	sort(l+1,l+1+m,cmp);
	sort(l2+1,l2+1+cnt,cmp2);
	for (int i=1;i<=n;i++) fa[i]=i, sum[i]=1;
	int j2=1;
	for (int i=1;i<=m;){
		int j, ff=0, ct=0;
		for (;j2<=cnt;j2++){
			if (l2[j2].q!=l2[j2-1].q || l2[j2].w!=l[i].w){
				for (int k=1;k<=ct;k++)
					fa[list[k]]=list[k],
					sum[list[k]]=f[list[k]],
					f[list[k]]=0;
		//	cout<<"ssss"<<endl;
		//	for (int j=1;j<=n;j++) cout<<j<<' '<<fa[j]<<' '<<sum[j]<<endl;
		//	cout<<"lyk"<<endl;
				ff=0;
				ct=0;
			}
			if (l2[j2].w!=l[i].w) break;
			if (ff) continue;
			int u=getfa(l2[j2].x), v=getfa(l2[j2].y);
		//	cout<<l2[j2].q<<' '<<u<<' '<<v<<endl;
			if (u==v){
				ans[l2[j2].q]=1;
				ff=1;
				continue;
			}
			else{
				if (!f[u]) f[u]=sum[u], list[++ct]=u;
				if (!f[v]) f[v]=sum[v], list[++ct]=v;
				if (sum[u]<sum[v]) fa[u]=v, sum[v]+=sum[u];
				else fa[v]=u, sum[u]+=sum[v];
			}
		}
		//cout<<j2<<' '<<cnt<<endl;
		if (j2>cnt) break;
		for (j=i;j<=m && l[j].w==l[i].w;j++)
			if (father(l[j].x)!=father(l[j].y))
				fa[fa[l[j].x]]=fa[l[j].y],
				sum[fa[l[j].y]]+=sum[fa[l[j].x]];
		i=j;
		//for (int j=1;j<=n;j++) cout<<j<<' '<<fa[j]<<' '<<sum[j]<<endl;
	}
	for (int i=1;i<=q;i++)
		if (ans[i]) cout<<"NO"<<endl;else cout<<"YES"<<endl;
	return 0;
}
