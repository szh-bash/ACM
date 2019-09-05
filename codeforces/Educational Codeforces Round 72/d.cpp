#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
#define N 30000
int n, m, cnt, nex[N], nu[N], flag[N], ans[N], co[N], ff[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int check(int u){
	if (flag[u]) return 1;
	if (ff[u]) return 0;
	flag[u]=1;
	ff[u]=1;
	int p=0;
	for (int j=nex[u];j;j=nex[j])
		if (!co[j]){
//			cout<<u<<' '<<nu[j]<<' '<<co[j]<<endl;
			p|=check(nu[j]);
			if (p) return p;
		}
	flag[u]=0;
	return p;
}
int main(){
	cnt=n=read();m=read();
	int p=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
		for (int j=1;j<=n;j++) ff[j]=flag[j]=0;
		flag[u]=ff[u]=1;
		if (check(v)) ans[i]=co[cnt]=p=1;
	}
	cout<<1+p<<endl;
	for (int i=1;i<=m;i++) printf("%d%s", ans[i]+1, i==m?"\n":" ");
	return 0;
}
