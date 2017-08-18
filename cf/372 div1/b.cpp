#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 1000000001
using namespace std;
int n, m, s, t, cnt, a[1010][1010], flag[3000], l[3000000], nu[300000], next[300000], next2[300000], fa[300000]; 
long long L, va[300000], dis1[200], dis2[2000], dis[2000];
void add(int x,int y, long long z){
	next[++cnt]=next[x];next[x]=cnt;nu[cnt]=y;va[cnt]=z;
	if (!z) flag[cnt]=1, va[cnt]=INF;
}
void add2(int x,int y, long long z){
	next2[++cnt]=next2[x];next2[x]=cnt;nu[cnt]=y;va[cnt]=z;fa[cnt]=x;
	if (!z) flag[cnt]=1, va[cnt]=1;
}
int main(){
	cin>>n>>m>>L>>s>>t;s++;t++; 
	cnt=n+((n+1)&1);
	for (int i=1;i<=m;i++){
		int u, v;
		long long vv;
		scanf("%d%d%I64d", &u, &v, &vv);
		u++;v++;
		a[u][v]=a[v][u]=vv;
		if (!vv) a[u][v]=a[v][u]=-1;
		add(u, v, vv);
		add(v, u, vv);
	}
	int le=0, ri=1;
	l[1]=s;
	for (int i=1;i<=n;i++) dis[i]=INF;
	dis[s]=0;
	while (le<ri){
		int u=nu[++le];
		int j=next[u], v;
		flag[u]=0;
		while (j){
			v=nu[j];
			if (dis[u]+va[j]<dis[v]){
				dis[v]=dis[u]+va[j];
				if (!flag[v]){
					flag[v]=1;
					l[++ri]=v;
				}
			}
			j=next[j];
		}
	}
	if (dis[t]<L) { cout<<"NO"<<endl;return 0;}
	cout<<"YES"<<endl;
	if (dis[t]==L){
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				if (a[i][j]>0) cout<<i<<' '<<j<<' '<<a[i][j]<<endl;
				else 
					if (a[i][j]==-1) cout<<i<<' '<<j<<' '<<INF<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=next[i];j;j=next[j])
			if (va[j]==INF) va[j]=1;
	le=0;
	ri=1;
	l[1]=s;
	for (int i=1;i<=n;i++) dis[i]=INF, flag[i]=0;
	dis[s]=0;
	while (le<ri){
		int u=nu[++le];
		int j=next[u], v;
		flag[u]=0;
		while (j){
			v=nu[j];
			if (dis[u]+va[j]<dis[v]){
				dis[v]=dis[u]+va[j];
				if (!flag[v]){
					flag[v]=1;
					l[++ri]=v;
				}
			}
			j=next[j];
		}
	}
	cout<<dis[t]<<endl;
	le=0;ri=1;
	l[1]=t;
	for (int i=1;i<=n;i++) dis1[i]=dis[i], dis[i]=INF, flag[i]=0;
	dis[t]=0;
	while (le<ri){
		int u=nu[++le];
		int j=next[u], v;
		flag[u]=0;
		while (j){
			v=nu[j];
			if (dis[u]+va[j]<dis[v]){
				dis[v]=dis[u]+va[j];
				if (!flag[v]){
					flag[v]=1;
					l[++ri]=v;
				}
			}
			j=next[j];
		}
	}
	for (int i=1;i<=n;i++) dis2[i]=dis[i];
	cnt=n+((n+1)&1);
	memset(next,0,sizeof(next));
	memset(flag,0,sizeof(flag));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int v=a[i][j];
			if (v==-1) v=1;
			if (dis1[i]+v+dis2[j]==dis1[t])
				add2(i,j,0);
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) if (a[i][j]==-1) a[i][j]=1;
	for (int i=n+((n+1)&1);i<=cnt;i++)
		if (flag[i] && dis1[fa[i]]+va[i]+dis2[nu[i]]==dis1[t]) {
			va[i]=L-dis1[t]+va[i];
			va[i^1]=L-dis1[t]+va[i^1];
			int le=0, ri=1;
			l[1]=s;
			for (int j=1;j<=n;j++) dis[j]=INF, flag[j]=0;
			dis[s]=0;
			while (le<ri){
				int u=nu[++le];
				int j=next[u], v;
				flag[u]=0;
				while (j){
					v=nu[j];
					if (dis[u]+va[j]<dis[v]){
						dis[v]=dis[u]+va[j];
						if (!flag[v]){
							flag[v]=1;
								l[++ri]=v;
							}
					}
					j=next[j];
				}
			}
			if(dis[t]==L){
				a[fa[i]][nu[i]]=a[nu[i]][fa[i]]=va[i];
				for (int i=1;i<=n;i++)
					for (int j=i+1;j<=n;j++)	 cout<<i<<' '<<j<<' '<<a[i][j]<<endl;
				return 0;
			}
			le=0;ri=1;
			l[1]=t;
			for (int j=1;j<=n;j++) dis1[j]=dis[j], dis[j]=INF, flag[j]=0;
			dis[t]=0;
			while (le<ri){
				int u=nu[++le];
				int j=next[u], v;
				flag[u]=0;
				while (j){
					v=nu[j];
					if (dis[u]+va[j]<dis[v]){
						dis[v]=dis[u]+va[j];
						if (!flag[v]){
							flag[v]=1;
								l[++ri]=v;
							}
					}
					j=next[j];
				}
			}
			for (int j=1;j<=n;j++) dis2[j]=dis[j];
		}
	return 0;
}
