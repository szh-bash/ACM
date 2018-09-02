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
#define K 15
#define N 100005
#define M 500000
#define mo 5000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
const ll INF=(ll) 1000000000*1000000;
struct zkjnb{
	int v, t;
}l[N*K*10];
int n, k, m, le, ri, flag[N][K], cnt, nex[M], nu[M], va[M];
ll dis[N][K];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void spfa(int k){
		while (le!=ri){
			int u=l[le+1==mo?le=0:++le].v, t=l[le].t;
			if (!flag[u][t]) continue;
			flag[u][t]=0;
			for (int j=nex[u];j;j=nex[j]){
				int v=nu[j];
				if (dis[u][t]+va[j]<dis[v][t]){
					dis[v][t]=dis[u][t]+va[j];
					if (!flag[v][t]){
						flag[v][t]=1;
						if (le!=ri){
							int j=le+1==mo?0:le+1;
							if (dis[l[j].v][l[j].t]>dis[v][t]){
								l[le].v=v;
								l[le].t=t;
								if (le) --le;else le=mo-1;
							}
							else{
								l[ri+1==mo?ri=0:++ri].v=v;
								l[ri].t=t;
							}
						}
						else{
							l[ri+1==mo?ri=0:++ri].v=v;
							l[ri].t=t;
						}
					}
				}
			}
		}
}
int main(){
	for (int _=read();_;_--){
		cnt=n=read();m=read();k=read();
		for (int i=1;i<=n;i++) nex[i]=0;
		for (int i=1;i<=m;i++){
			int u=read(), v=read(), w=read();
			add(u, v, w);
		}
		for (int i=1;i<=n;i++)
			for (int j=0;j<=k;j++) dis[i][j]=INF;
		dis[1][k]=0;
		le=0, ri=1, l[1].v=1, l[1].t=k, flag[1][k]=1;
		spfa(k);
		while (k--){
			for (int i=1;i<=n;i++)
				for (int j=nex[i];j;j=nex[j])
					dis[nu[j]][k]=min(dis[nu[j]][k],dis[i][k+1]);
			for (int i=1;i<=n;i++) l[i].v=i, l[i].t=k, flag[i][k]=1;
			le=0, ri=n;
			spfa(k);
		}
		cout<<dis[n][0]<<endl;
	}
    return 0;
}
