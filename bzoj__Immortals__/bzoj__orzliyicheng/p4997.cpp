#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 101 
typedef long long ll;
using namespace std;
int b[]={0,-1,0,1};
int d[]={-1,0,1,0};
int n, K , R, cnt, ans, tot[N*N], g[N][N];
bool f[N][N][4];
int read(){
    int p=0;
    char ch=getchar();
    while (ch<'0' || ch>'9') ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p;
}
void upd(int x1, int y1, int x2, int y2){
	for (int i=0;i<4;i++)
		if (x1+b[i]==x2 && y1+d[i]==y2){
			f[x1][y1][i]=1;
			return;
		}
}
void dfs(int x, int y){
	if (x<1 || x>n || y<1 || y>n || g[x][y]) return;
	g[x][y]=cnt;
	for (int i=0;i<4;i++)
		if (!f[x][y][i])
			dfs(x+b[i],y+d[i]);
}
int main(){
	n=read();K=read();R=read();
	for (int i=1;i<=R;i++){
		int x1=read(), y1=read(), x2=read(), y2=read();
		upd(x1,y1,x2,y2);
		upd(x2,y2,x1,y1);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!g[i][j])
				cnt++,
				dfs(i,j);
	for (int i=1;i<=K;i++){
		int x=read(), y=read();
		tot[g[x][y]]++;
	}
	for (int i=cnt;i;i--){
		K-=tot[i];
		ans+=tot[i]*K;
	}
	cout<<ans<<endl;
    return 0;
}
