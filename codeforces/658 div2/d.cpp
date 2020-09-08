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
#define N 2005
int n, a[N*2], b[N*2], f[N];
void solve(){
	n=read();
	int ct=0, h=0;
	for (int i=1;i<=2*n;i++){
		a[i]=read();
		if (a[i]>a[h]) b[++ct]=1, h=i;
		else b[ct]++;
	}
	f[0]=1;
	for (int j=1;j<=n;j++) f[j]=0;
	for (int i=1;i<=ct;i++)
		for (int j=n;j>=b[i];j--)
			f[j]|=f[j-b[i]];
	if (f[n]) puts("YES");else puts("NO");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
