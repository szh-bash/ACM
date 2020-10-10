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
#define N 100005
#define M 25
#define CH 26
int n, m, pos[M][CH], g[N][M][M], f[N][M];
char s[N], st[M];
void buildF(){
	for (int j=0;j<26;j++) pos[m+1][j]=m+1;
	for (int i=m;i;i--){
		for (int j=0;j<26;j++)
			pos[i][j]=pos[i+1][j];
		pos[i][st[i]-'a']=i;
	}
	for (int i=1;i<=n;i++)
		for (int j=0;j<=m;j++)
			f[i][j]=n+1;
	for (int j=1;j<=m+1;j++){
		g[n+1][j][0]=n+1;
		for (int k=1;k<=m;k++) g[n+1][j][k]=999999999;
	}
	for (int i=n;i;i--){
		for (int j=1;j<=m;j++){
			g[i][j][0]=f[i][0]=i;
			for (int k=1;k<=m-j+1;k++){
				g[i][j][k]=g[i+1][j][k];
				if (pos[j][s[i]-'a']<=m)
					g[i][j][k]=min(g[i][j][k],
								   g[i+1][pos[j][s[i]-'a']+1][k-1]-(k==1));
				f[i][k]=min(g[i][j][k],f[i][k]);
			}
			for (int k=m-j+2;k<=m;k++)
				g[i][j][k]=999999999;
		}
		g[i][m+1][0]=i;
		for (int k=1;k<=m;k++) g[i][m+1][k]=999999999;
	}
}
void solve(){
	scanf("%s%s", s+1, st+1);
	n=strlen(s+1);
	m=strlen(st+1);
	buildF();
	for (int _=read();_;_--){
		int le=read(), ri=read();
		for (int i=m;i>=0;i--)
			if (f[le][i]<=ri){
				printf("%d\n",ri-le+1-i+m-i);
				break;
			}
	}
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
