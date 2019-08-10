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
#define N 4000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m;
char s[N][N];
int g[N][N], f[N][N], r[N][N], id[N], q[N], ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) scanf("%s", s[i]+1);
	for (int i=1;i<=n;i++) s[i][m+1]='0';
	m++;
	for (int i=1;i<=n;i++){
		int ct=0;
		for (int j=1;j<=m;j++){
			f[i][j]=(1+f[i-1][j])*(s[i][j]=='1');
			if (f[i][j]>q[ct]){
				q[++ct]=f[i][j];
				id[ct]=j;
				g[i][j]=j;
				if (g[i-1][j]<g[i][j]) ans++;
			}
			else if (f[i][j]==q[ct]){
				g[i][j]=g[i][id[ct]];
			}
			else if (f[i][j]<q[ct]){
				int tmp=j;
				while (ct && q[ct]>f[i][j]){
					r[i][id[ct]]=j;
					tmp=g[i][id[ct]];
					if (g[i-1][id[ct]]==g[i][id[ct]] && r[i-1][id[ct]]>r[i][id[ct]]) ans++;
					ct--;
				}
				if (q[ct]==f[i][j]) g[i][j]=g[i][id[ct]];
				else if (f[i][j]){
					q[++ct]=f[i][j];
					id[ct]=j;
					g[i][j]=tmp;
					if (g[i-1][j]<g[i][j]) ans++;
				}
			}
//			cout<<i<<' '<<j<<' '<<ans<<' '<<ct<<endl;
		}
//		cout<<ans<<endl;
	}
	cout<<ans<<endl;
    return 0;
}
