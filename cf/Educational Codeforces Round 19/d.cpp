#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long 
#define MN 600005
#define INF 0x3FFFFFFF
using namespace std;
int n,rt,a[MN],b[MN],son[MN][2],gs,ans;
bool u[MN];
inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
} 
void dfs(int x,int L,int R)
{
	if (!x) return;
	if (L>=R) return;
	if (a[x]>L && a[x]<R) b[++gs]=a[x];
	dfs(son[x][0],L,min(R,a[x]));
	dfs(son[x][1],max(L,a[x]),R);
}
int main()
{
	register int i,j,x,y,lt;
	n=read();
	for (i=1;i<=n;++i)
	{
		a[i]=read(); son[i][0]=read(); son[i][1]=read();
		if (son[i][0]==-1) son[i][0]=0;
		if (son[i][1]==-1) son[i][1]=0;
		u[son[i][0]]=true; u[son[i][1]]=true;
	}
	for (i=1;i<=n;++i) if (!u[i]) {rt=i; break;}
	dfs(rt,-INF,INF);
	sort(a+1,a+n+1); a[0]=-INF;
	sort(b+1,b+gs+1); b[0]=-INF; b[gs+1]=INF;
	for (i=1,j=0;i<=n;++i)
	{
		while (b[j]<a[i]) ++j;
		if (a[i]!=b[j]) ++ans;
	}
	printf("%d",ans);
}
