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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 10005
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int g[N];
int flag[N][N], n, m, a[N][N];
char s[N];
inline bool check(int x, int y){
	return 1<=x && x<=n && 1<=y && y<=m;
}
void dfs(int x, int y){
	flag[x][y]=1;
	int d = a[x][y];
	if (check(x+dx[d], y+dy[d])){
		if (!flag[x+dx[d]][y+dy[d]]) dfs(x+dx[d], y+dy[d]);
		flag[x][y]=flag[x+dx[d]][y+dy[d]];
	}
	else flag[x][y]++;
}
int main(){
	n=read(), m=read();
	g['A']=3;g['D']=1;g['W']=0;g['S']=2;
	for (int i=1;i<=n;i++){
		scanf("%s", s+1);
		for (int j=1;j<=m;j++) a[i][j]=g[s[j]];
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (!flag[i][j]) dfs(i,j);
			ans+=flag[i][j]>1;
		}
	cout<<ans<<endl;
    return 0;
}
