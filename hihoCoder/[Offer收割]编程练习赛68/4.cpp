#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 1000000
using namespace std;
int n, k;
int nex[N*5],nu[N*5], cnt, flag[N], d[N], ans;
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
void dfs(int u){
	flag[u]=d[u]=1;
	for (int j=nex[u];j;j=nex[j]){
		int v=nu[j];
		if (flag[v]) continue;
		dfs(v);
		ans=max(ans,d[v]+d[u]);
		d[u]=max(d[u],d[v]+1);
	}
}
int main(){
	cnt=n=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u, v);
		add(v, u);
	}
	dfs(1);
	ans=max(ans,d[1]);
	int j=1;
	while (j<ans){
		k++;
		j<<=1;
	}
	cout<<k<<endl;
	return 0;
}
