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
#define N 3000
int d[N], h[N];
int solve(){
	int n=read();
	int x=read();
	int ma=0;
	int mad=-2000000000;
	for (int i=1;i<=n;i++)
		d[i]=read(),
		h[i]=read(),
		ma=max(ma, d[i]),
		mad=max(mad, d[i]-h[i]);
	if (ma>=x) return 1;
	if (mad<=0) return -1;
	return (x-ma-1)/mad+2;
}
int main(){
	for (int _=read();_;_--)
		cout<<solve()<<endl;
	return 0;
}
