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
#define N 3000000
#define mo 500000
#define INF (ll)500000000*50000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, cnt, ct, dir[N], ans[N], flag[N], nu[N], nex[N], l[mo], tag[N];
ll va[N], dis[N], dist[N][4];
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
void add(int &x, int b){
	x+=b;
	if (x>=mo) x-=mo;
}
void sub(int &x, int b){
	x-=b;
	if (x<0) x+=mo;
}
void spfa(int st, int ed, int t){
	for (int i=1;i<=n;i++) 
		flag[i]=0,
		dis[i]=INF;
	int le=0, ri=1;
	flag[l[1]=st]=1;
	dis[st]=0;
	while (le!=ri){
		add(le,1);
		int u=l[le];
		flag[u]=0;
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (dis[u]+va[j]<dis[v]){
				dis[v]=dis[u]+va[j];
				if (!flag[v]){
					flag[v]=1;
					add(le,1);
					int k=le;
					sub(le,1);
					if (le!=ri && dis[v]<dis[l[k]]){
						l[le]=v;
						sub(le,1);
					}
					else{
						add(ri,1);
						l[ri]=v;
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++) dist[i][t]=dis[i];
}
void bfs(){
	for (int i=1;i<=n;i++) flag[i]=0;
	flag[1]=l[1]=1;
	for (int le=1, ri=1;le<=ri;le++){
		int u=l[le];
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (tag[j] || flag[v]) continue;
			flag[v]=1;
			dir[v]=u;
			l[++ri]=v;
		}
	}
}
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read()+1, v=read()+1, d=read();
		add(u,v,d);
		add(v,u,d);
	}
	//spfa(1,2,0);
	spfa(2,1,1);
	for (int i=1;i<=n;i++){
		for (int j=nex[i];j;j=nex[j]){
			int v=nu[j];
			if (dist[v][1]+va[j]==dist[i][1]) tag[j]=1;
		}
	}
	bfs();
	if (!flag[2]){
		cout<<"impossible"<<endl;
		return 0;
	}
	for (int i=2;i;i=dir[i]) ans[++ct]=i;
	printf("%d", ct);
	for (int i=ct;i;i--) printf(" %d", ans[i]-1);cout<<endl;
    return 0;
}
