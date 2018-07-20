#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 1000000
using namespace std;
int n, k, ans;
long f[N], g[N], c[N], nex[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=n;i;i--){
		nex[i]=g[c[i]];
		g[c[i]]=i;
	}
	f[0]=N;
	for (int i=n-1;i;i--)
		f[i]=min(f[i+1],f[nex[i]])+1;
	cout<<f[1]<<endl;
	return 0;
}
