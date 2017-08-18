#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 100100
#define M 100100
using namespace std;
long long ans;
int q[N*2][2], g[N*2][2], n, cnt, flag, qqq[N], qu[N*2], nu[N*4], fl[N*2], next[N*4], va[N*4], size[N], f[N], u[N], done[N];
void add(int u, int v, int w){
	next[++cnt]=next[u];next[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void dfs(int t, int fa){
	u[++cnt]=t;
	size[t]=1;
	f[t]=0;
	for (int i=next[t];i;i=next[i])
		if (!done[nu[i]] && fa!=nu[i]){
			dfs(nu[i],t);
			size[t]+=size[nu[i]];
			f[t]=max(f[t],size[nu[i]]);
		}
}
int find(int t){
	cnt=0; 
	int Min=0xfffffff, p;
	dfs(t,0);
	for (int i=1;i<=cnt;i++)
		if (max(f[u[i]],size[t]-size[u[i]])<Min)
			Min=max(f[u[i]],size[t]-size[u[i]]), p=u[i];
	return p;
}
void dfs2(int t, int fa, int d){
	if (fl[M+d]) flag=1;else flag=0;
	fl[M+d]++;
	q[M+d][flag^0]++;
	qu[++cnt]=d;
	for (int i=next[t];i;i=next[i])
		if (!done[nu[i]] && fa!=nu[i])
			dfs2(nu[i],t,d+va[i]);
	fl[M+d]--;
}
void work(int t){
	int root=find(t), ct=0;
	done[root]=1;
	for (int i=next[root];i;i=next[i])
		if (!done[nu[i]]){
			cnt=0;
			dfs2(nu[i],root,va[i]);
			ans+=(long long)g[M][0]*q[M][0]+q[M][1];
			for (int i=1;i<=cnt;i++)
				if (!fl[qu[i]+M]){
					int d1=qu[i]+M, d2=M-qu[i];
					fl[d1]=1;
					ans+=(long long)q[d1][1]*g[d2][0]+(long long)q[d1][0]*g[d2][1]
						 +(long long)q[d1][1]*g[d2][1];
			//cout<<ans<<endl;
				}
			for (int i=1;i<=cnt;i++){
				int dd=qu[i]+M;
				if (fl[dd]) fl[dd]=0;
				g[dd][0]+=q[dd][0];
				g[dd][1]+=q[dd][1];
				q[dd][0]=q[dd][1]=0;
				qqq[++ct]=dd;
			}
		}
	for (int i=1;i<=ct;i++) g[qqq[i]][1]=g[qqq[i]][0]=0;
	for (int i=next[root];i;i=next[i])
		if (!done[nu[i]]) work(nu[i]);
}
int read()
{
 int ret=0;
 char c;
 while((c=getchar())!=' '&&c!='\n')
  ret=ret*10+c-'0';
 return ret;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n=read();
	cnt=n;
	for (int i=1;i<n;i++){
		int u=read(), v=read(), w=read();
		if (!w) w--;
		add(u,v,w);
		add(v,u,w);
	}
	work(1);
	cout<<ans<<endl;
	return 0;
}
