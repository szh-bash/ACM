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
int n, k, m, flag[N][K], cnt, nex[M], nu[M], va[M];
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
int main(){
	for (int _=read();_;_--){
		cnt=n=read();m=read();k=read();
		for (int i=1;i<=n;i++) nex[i]=0;
		for (int i=1;i<=m;i++){
			int u=read(), v=read(), w=read();
			add(u, v, w);
		}
		int le=0, ri=1;
		for (int i=1;i<=n;i++)
			for (int j=0;j<=k;j++) dis[i][j]=INF;
		for (int j=0;j<=k;j++) dis[1][j]=0;
		l[1].v=1;
		l[1].t=0;
		flag[1][0]=1;
	//	double sum=0;
	//	int tot=0;
		while (le!=ri){
			int u=l[le+1==mo?le=0:++le].v, t=l[le].t;
			if (!flag[u][t]) continue;
		/*	if (dis[u][t]>sum){
				l[ri+1==mo?ri=0:++ri].v=u;
				l[ri].t=t;
				continue;
			}
			sum=(sum-(double)dis[u][t]/tot)*((double)tot/(tot-1)); 
			--tot;*/
			flag[u][t]=0;
			for (int j=nex[u];j;j=nex[j]){
				int v=nu[j];
				if (dis[u][t]+va[j]<dis[v][t]){
					dis[v][t]=dis[u][t]+va[j];
					for (int p=t+1;p<=k;p++)
						if (dis[v][p]>=dis[v][t])
							flag[v][p]=0,
							dis[v][p]=dis[v][t];
						else break;
					if (!flag[v][t]){
				//		sum=sum*((double)tot/(tot+1))+(double)dis[v][t]/(tot+1);
				//		++tot;
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
				if (t<k && dis[u][t]<dis[v][t+1]){
					dis[v][t+1]=dis[u][t];
					for (int p=t+2;p<=k;p++)
						if (dis[v][p]>=dis[v][t+1])
							flag[v][p]=0,
							dis[v][p]=dis[v][t+1];
						else break;
					if (!flag[v][t+1]){
					//	sum=sum*((double)tot/(tot+1))+(double)dis[v][t+1]/(tot+1);
					//	++tot;
						flag[v][t+1]=1;
						if (le!=ri){
							int j=le+1==mo?0:le+1;
							if (dis[l[j].v][l[j].t]>dis[v][t+1]){
								l[le].v=v;
								l[le].t=t+1;
								if (le) --le;else le=mo-1;
							}
							else{
								l[ri+1==mo?ri=0:++ri].v=v;
								l[ri].t=t+1;
							}
						}
						else{
							l[ri+1==mo?ri=0:++ri].v=v;
							l[ri].t=t+1;
						}
					}
				}
			}
		}
		cout<<dis[n][k]<<endl;
	}
    return 0;
}
