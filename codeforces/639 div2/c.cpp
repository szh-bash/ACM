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
int b[300000];
void solve(){
	int ans=1;
	int n=read();
	for (int i=0;i<n;i++) b[i]=0;
	for (int i=1;i<=n;i++){
		int x=(read()%n+i+n)%n;
		if (!b[x]) b[x]++;
		else ans=0;
	}
	if (ans) puts("YES");
	else puts("NO");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
