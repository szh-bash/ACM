#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 400000
#define M (N*3)
typedef long long ll;
using namespace std;
int cnt, n, m, ans, p[N], tag[N], flag[N], eend[N], nex[M], nu[M];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	cnt=n=read();m=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read();
		nex[++cnt]=nex[u];
		nex[u]=cnt;
		nu[cnt]=v;
		if (v==p[n]) tag[u]=1;
	}
	int ct=0;
	for (int i=n-1;i;i--){
		int u=p[i];
		int tot=0;
		for (int j=nex[u];j;j=nex[j])
			if (!eend[nu[j]]) tot+=flag[nu[j]];
		if (tot==ct && tag[u]) ans++, eend[u]=1; else ct++;
		flag[u]=1;
	}
	cout<<ans<<endl;
	return 0;
}
