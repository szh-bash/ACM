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
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void dfs(int u){
	int v1=0, v2=0;
	for (int j=nex[u];j;j=nex[j])
		if (!v1) v1=nu[j];
		else v2=nu[j];
	if (v1){
		for (int 
	}
	else f[u][0]=0, f[u][1]=1;
}
int main(){
	for (int _=read();_;_--){
		n=read();
		for (int i=1;i<n;i++) a[i]=read();
		cnt=2*n-1;
		for (int i=1;i<=cnt;i++) nex[i]=0;
		for (int i=2;i<=2*n-1;i++)
			fa[i]=read(),
			add(fa[i],i);
		dfs(1);
		cout<<max(f[1][0],f[1][1]);
	}
    return 0;
}
