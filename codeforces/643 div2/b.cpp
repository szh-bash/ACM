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
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 400000
int n;
int f[N], e[N], g[N];
int main(){
	for (int _=read();_;_--){
		n=read();
		for (int i=1;i<=n;i++) e[i]=read();
		sort(e+1,e+1+n);
		for (int i=1;i<=n;i++){
			if (e[i]<=i)
				f[i] = g[i-e[i]]+1;
			else f[i]=0;
			g[i]=max(g[i-1], f[i]);
		}
		cout<<g[n]<<endl;
	}
	return 0;
}
