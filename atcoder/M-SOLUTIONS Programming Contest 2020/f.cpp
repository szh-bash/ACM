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
#define mo 1000000007
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 200005
#define LIM 200005
#define inf 999999999
vector<int>pk[4][LIM*3], nk[4][LIM*3];
int n, row[4][LIM][3], col[4][LIM][3], id[200];
struct node{
	int n, x;
}g[N];
bool cmp(node a, node b){
	return a.x<b.x;
}
int ans;
void calc(int dir0, int dir1, int t0, int t1, int i){
	int l1=pk[dir0][i].size(), l2=pk[dir1][i].size();
	int ct=0;
	for (int j=0;j<l1;j++)
		g[++ct].n=t0,
		g[ct].x=pk[dir0][i][j];
	for (int j=0;j<l2;j++)
		g[++ct].n=t1,
		g[ct].x=pk[dir1][i][j];
	sort(g+1,g+1+ct,cmp);
	int x0=-1, x1=-1;
	for (int j=1;j<=ct;j++)
		if (g[j].n==1){
			x1=g[j].x;
			if (x0>=0){
				ans=min(ans,(x1-x0)*10/2);
				cout<<x0<<' '<<x1<<endl; 
			} 
		}
		else x0=g[j].x;
}
int main(){
	n=read();
	ans=inf;
	id['R']=0, id['L']=1;
	id['U']=2, id['D']=3;
	int lim=200000, lim2=lim*2;
	for (int i=1;i<=n;i++){
		int x=read(), y=read();
		char dir[2];
		scanf("%s", dir);
		int d=id[dir[0]];
		pk[d][y-x+lim].push_back(x);
		nk[d][y+x+lim].push_back(x);
		if (!row[d][y][0]) 
			row[d][y][1]=row[d][y][2]=x,
			row[d][y][0]++;
		else 
			row[d][y][1]=min(row[d][y][1],x),
			row[d][y][2]=max(row[d][y][2],x);
		if (!col[d][x][0])
			col[d][x][1]=col[d][x][2]=y,
			col[d][x][0]++;
		else
			col[d][x][1]=min(col[d][x][1],y),
			col[d][x][2]=max(col[d][x][2],y);
	}
	int mir, mar, mic, mac;
	for (int i=0;i<=lim;i++)
		if (row[0][i][0] && row[1][i][0]) {
			mir=row[0][i][1];
			mar=row[1][i][2];
			if (mir<mar) ans=min(ans,(mar-mir)*10/2);
		}
	for (int i=0;i<=lim;i++)
		if (col[2][i][0] && col[3][i][0]) {
			mic=col[2][i][1];
			mac=col[3][i][2];
			if (mic<mac) ans=min(ans,(mac-mic)*10/2);
		}
	cout<<ans<<endl;
	for (int i=0;i<=lim*3;i++){
		if (pk[0][i].size()>0 && pk[3][i].size()>0) calc(0,3,0,1,i);
		if (pk[1][i].size()>0 && pk[2][i].size()>0) calc(1,2,1,0,i);
		if (nk[0][i].size()>0 && nk[2][i].size()>0) calc(0,2,0,1,i);
		if (nk[1][i].size()>0 && nk[3][i].size()>0) calc(1,3,1,0,i);
	}
	if (ans==inf) puts("SAFE");
	else printf("%d", ans);
    return 0;
}
