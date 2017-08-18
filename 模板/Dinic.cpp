#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define N 10000
#define M 200000
#define INF 1e9
using namespace std;
int head[N],next[M],to[M],len[M],pr[M];
int n,m,cnt,S,T,mlen;
int tim[1000][1000];
int dis[N],pre[N],q[M];
bool vis[N];
inline void add(int u,int v,int r,int w)
{
    to[cnt]=v; len[cnt]=r; pr[cnt]=w; next[cnt]=head[u]; head[u]=cnt++;
    to[cnt]=u; len[cnt]=0; pr[cnt]=-w; next[cnt]=head[v]; head[v]=cnt++;
}
inline void read()
{
    memset(head,-1,sizeof head); cnt=0;
    scanf("%d%d",&m,&n);
    S=0; T=n+n*m+1;
    for(int i=1,a;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&tim[i][j]);
    for(int i=1;i<=n;i++) add(S,i,1,0);
    for(int i=n+n*m;i>=n+1;i--) add(i,T,1,0);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                add(i,j*n+k,1,(n-k+1)*tim[i][j]);
}
inline bool spfa(){
	memset(pre,-1,sizeof(pre));
	memset(dis,0x3f,sizeof(dis));
	int h=1, t=2, sta;
	q[1]=S;dis[S]=0;vis[S]=true;
	while (h<t){
		sta=q[h++];vis[sta]=false;
		for (int i=head[sta];~i;i=next[i])
			if (len[i] & dis[to[i]] >dis[sta]+ pr[i]){
				dis[to[i]]=dis[sta]+pr[i];
				pre[to[i]]=i;
				if (!vis[to[i]]) q[t++]=to[i], vis[to[i]]=true;
			}
	}
	return pre[T]!=-1;
}
inline void updata(){
	mlen=INF;
	for (int i=pre[T];i;i=pre[to[i^1]])
		mlen=min(mlen,len[i]);
	for (int i=pre[T];i;i=pre[to[i^1]])
		len[i]-=mlen, len[i^1]+=mlen;	
}
inline void go(){
	int ans=0;
	while (spfa()) updata(), ans+=dis[T]*mlen;
	printf("%.2lf\n", double(ans)/n);
}
int main(){
	read();
	go();
	return 0;
}

