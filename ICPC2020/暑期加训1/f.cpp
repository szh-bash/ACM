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
int solve(int x){
	for (int i=1;i<=1e4;i++) f[i]=0;
	for (int i=1;i<=n;i++) f[a[i]]=i;
	f[a[x]]=-1;
	for (int i=1e4;i;i--)
		if (f[i])
			for (int j=1;j<=n;j++)
				if (j!=x && a[j]<i)
					f[i-a[j]]=i;
	if (f[m]){
		return 1;
	}
	for (int j=m;j;j=f[j]){
		ans++;
		
		if (f[j]==j) break;
	}
}
int dfs(int t, int p){
	if (p==m){
		solved();
		flag=1;
		return 1;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j+p<=min(m,a[i]) && f[i][j];j++){
			c[t]=i;
			d[t]=j;
			if (dfs(t+1,j+p)) return 1;
		}
	return 0;
}
int main(){
	n=read(), m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	dfs(1,0);
	puts("-1");
    return 0;
}
