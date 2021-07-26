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
typedef long long ll;
using namespace std;
#define N 20
int n, a[N], c[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool dfs(int t){
	if (t>n){
		int sum=0;
		for (int i=1;i<=n;i++) sum+=c[i]*a[i];
		for (int i=1;i<=n;i++)
			if (sum-c[i]*a[i]==a[i]) return 1;
		return 0;
	}
	for (int i=-1;i<=1;i++){
		c[t]=i;
		if (dfs(t+1)) return 1;
	}
	return 0;
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (dfs(1)) puts("YES");
	else puts("NO");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
