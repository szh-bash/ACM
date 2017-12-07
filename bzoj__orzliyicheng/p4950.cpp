#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 110
typedef long long ll;
using namespace std;
int cnt, n, m, g[N][2], fr[N*2], flag[N*2], nex[N*200], nu[N*200], a[N][N];
ll ans;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
bool find(int u){
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v]) continue;
		flag[v]=1;
		if (!fr[v] || find(fr[v])) {
			fr[v]=u;
			return 1;
		}
	}
	return 0;
}
int main(){
	cnt=(n=read())+(m=read());
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) (a[i][j]=read())?(ans+=a[i][j]-1):0;
	for (int i=1;i<=n;i++){
		int ma=0;
		for (int j=1;j<=m;j++) ma=max(ma,a[i][j]);
		if (ma)	ans-=ma-1;
		g[i][0]=ma;
	}
	for (int j=1;j<=m;j++){
		int ma=0;
		for (int i=1;i<=n;i++) ma=max(ma,a[i][j]);
		if (ma) ans-=ma-1;
		g[j][1]=ma;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (g[i][0]==g[j][1] && a[i][j])
				add(i,j+n),
				add(j+n,i);
	for (int i=1;i<=n;i++){
		memset(flag,0,sizeof(flag));
		if (find(i)) ans+=g[i][0]-1;
	}
	cout<<ans<<endl;
	return 0;
}
