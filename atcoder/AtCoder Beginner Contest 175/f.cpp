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
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 55
#define M 25
#define ND 60000000
#define EDGE 90000000
#define mo 1000000007
#define mo2 1000000009
int n, l[N], c[N], pre[N];
char s[N][M], res[N][M];
ll hs[N][M], hr[N][M], poww[M];
ll hs2[N][M], hr2[N][M], poww2[M];
int nex[EDGE], nu[EDGE];
ll dist[ND], va[EDGE];
bool flag[ND];
int st, cnt;
ll INF=1ll*1999999999*1999999999;
struct node{
	int n;
	ll dist;
	node (int n, ll dist): n(n), dist(dist){}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;} 
};
priority_queue<node, vector<node>, greater<node> > q;
void add(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
inline ll calc(ll h[N][M], int x, int y, int det, ll power[], int mod){
	return ((h[x][y+det]-h[x][y]*power[det])%mod+mod)%mod;
}
inline bool check(int i, int j, int k, int p, int det){
	return calc(hs,i,j,det,poww,mo)==calc(hr,k,p,det,poww,mo) && 
		   calc(hs2,i,j,det,poww2,mo2)==calc(hr2,k,p,det,poww2,mo2);
}
int main(){
	n=read();
	int seed=133;
	int seed2=131;
	poww[0]=poww2[0]=1;
	for (int i=1;i<M;i++)
		poww[i]=1ll*poww[i-1]*seed%mo,
		poww2[i]=1ll*poww2[i-1]*seed2%mo2;
	for (int i=1;i<=n;i++){
		scanf("%s", &s[i]);
		c[i]=read();
		l[i]=strlen(s[i]);
		pre[i]=pre[i-1]+l[i];
		for (int j=0;j<l[i];j++) 
			res[i][j]=s[i][l[i]-1-j];
		for (int j=1;j<l[i];j++)
			hs[i][j]=(hs[i][j-1]*seed+s[i][j])%mo,
			hr[i][j]=(hr[i][j-1]*seed+res[i][j])%mo,
			hs2[i][j]=(hs2[i][j-1]*seed2+s[i][j])%mo2,
			hr2[i][j]=(hr2[i][j-1]*seed2+res[i][j])%mo2;
	}
	ll ans=INF;
	for (int beg=1;beg<=n;beg++){
		#define get(i,j,x,y) (pre[i-1]+j+1)*1010+pre[x-1]+y+1
		st=1005*1010, cnt=st;
		for (int i=1;i<=cnt;i++) nex[i]=0;
		for (int y=1;y<=n;y++)
			if (s[beg][0]==res[y][0])
				dist[get(beg,0,y,0)]=INF,
				flag[get(beg,0,y,0)]=0,
				add(st,get(beg,0,y,0),c[beg]+c[y]);
		for (int i=1;i<=n;i++)
			for (int k=1;k<=n;k++){
				for (int j=0,p=0;j<l[i];j++){
					int u=get(i,j,k,p);
					dist[u]=INF;
					flag[u]=0;
					if (j<l[i]-1){
						int det=min(l[i]-j-1,l[k]-p-1);
						if (check(i,j,k,p,det)) add(u,get(i,j+det,k,p+det),0);
					}
					else{
						for (int x=1;x<=n;x++)
							if (s[x][0]==res[k][p+1]) 
								add(u,get(x,0,k,p+1),c[x]);
					}
				}
				if (l[k]>1)
				for (int j=0,p=l[k]-1;j<l[i];j++){
					int u=get(i,j,k,p);
					dist[u]=INF;
					flag[u]=0;
					if (j<l[i]-1){
						for (int x=1;x<=n;++x)
							if (s[i][j+1]==res[x][0]) 
								add(u,get(i,j+1,x,0),c[x]);
					}
					else{
						for (int x=1;x<=n;++x)
							for (int y=1;y<=n;y++)
								if (s[x][0]==res[y][0])
									add(u,get(x,0,y,0),c[x]+c[y]);
					}
				}
				if (l[k]>2)
				for (int j=0,p=1;p<l[k]-1;++p){
					int u=get(i,j,k,p);
					dist[u]=INF;
					flag[u]=0;
					int det=min(l[i]-j-1,l[k]-p-1);
					if (check(i,j,k,p,det)) add(u,get(i,j+det,k,p+det),0);
				}
				if (l[k]>2 && l[i]>1)
				for (int j=l[i]-1,p=1;p<l[k]-1;p++){
					int u=get(i,j,k,p);
					dist[u]=INF;
					flag[u]=0;
					for (int x=1;x<=n;x++)
						if (s[x][0]==res[k][p+1]) 
							add(u,get(x,0,k,p+1),c[x]);
				}
			}
		dist[st]=0;
		q.push(node(st,0));
		while (!q.empty()){
			node curNode=q.top();
			q.pop();
			int u=curNode.n;
			flag[u]=1;
			for (int j=nex[u];j;j=nex[j]){
				int v=nu[j];
				if (!flag[v] && dist[u]+va[j]<dist[v])
					dist[v]=dist[u]+va[j],
					q.push(node(v,dist[v]));
			}
			while (!q.empty() && flag[q.top().n]) q.pop();
		}
		ll res=INF;
		for (int x=1;x<=n;x++)
			res=min(res,dist[get(x,l[x]-1,beg,l[beg]-1)]);
		ans=min(ans,res);
	}
	if (ans==INF) ans=-2;
	cout<<ans/2<<endl;
    return 0;
}

