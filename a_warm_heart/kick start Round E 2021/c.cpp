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
#define N 1005
#define M 3000005
int n, m, cnt, g[N][N], flag[N*N], ans;
int nex[M], nu[M];
char s[N][N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define get_x(x) ((x)-1)/m+1
#define get_y(y) ((y)-1)%m+1
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
	// cout<<u<<' '<<v<<' '<<get_x(u)<<' '<<get_y(u)<<' '<<get_x(v)<<' '<<get_y(v)<<endl;
}
void dfs(char ch, int x){
	for (int j=nex[x];j;j=nex[j])
		if (!flag[nu[j]]){
			// cout<<ch<<' '<<x<<' '<<nu[j]<<' '<<get_x(x)<<' '<<get_y(x)<<' '<<get_x(nu[j])<<' '<<get_y(nu[j])<<endl;
			ans+=s[get_x(nu[j])][get_y(nu[j])]!=ch;
			s[get_x(nu[j])][get_y(nu[j])]=ch;
			flag[nu[j]]=1;
			dfs(ch, nu[j]);
		}
}
void solve(int o){
	n=read(), m=read();
	cnt=n*m;
	ans=0;
	for (int i=1;i<=cnt;i++) nex[i]=0;
	for (int i=1;i<=n;i++){
		scanf("%s", s[i]+1);
		for (int j=1;j<=m;j++)
			g[i][j]=(i-1)*m+j,
			flag[g[i][j]]=0;
	}
	for (int i=1;i<=n;i++){
		int px=0;
		for (int j=1;j<=m+1;j++)
			if (j<=m && s[i][j]!='#'){
				if (!px) px=j;
			}
			else{
				if (!px) continue;
				int l=j-px;
				for (int k=1;k<=l/2;k++)
					add(g[i][px+k-1], g[i][j-k]),
					add(g[i][j-k], g[i][px+k-1]);
				px=0;
			}
	}
	// puts("");
	for (int j=1;j<=m;j++){
		int py=0;
		for (int i=1;i<=n+1;i++)
			if (i<=n && s[i][j]!='#'){
				if (!py) py=i;
			}
			else{
				if (!py) continue;
				int l=i-py;
				for (int k=1;k<=l/2;k++)
					add(g[py+k-1][j], g[i-k][j]),
					add(g[i-k][j], g[py+k-1][j]);
				py=0;
			}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]!='.' && s[i][j]!='#' && !flag[g[i][j]]){
				flag[g[i][j]]=1,
				dfs(s[i][j], g[i][j]);
				// puts("");
			}
	printf("Case #%d: %d\n", o, ans);
	for (int i=1;i<=n;i++) printf("%s\n", s[i]+1);
}
int main(){
	for (int _=read(), o=1;_;_--, o++) solve(o);
    return 0;
}
