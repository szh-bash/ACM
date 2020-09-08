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
#define N 2000
char a[N], b[N];
int ans[N*4];
void solve(){
	int n=read();
	scanf("%s%s", a, b);
	int tmp=0;
	for (int i=0;i<n;i++)
		if (a[i]!=b[i]) ans[tmp+1]=i+1, ans[tmp+2]=1, ans[tmp+3]=i+1, tmp+=3;
	printf("%d", tmp);
	for (int i=1;i<=tmp;i++) printf(" %d", ans[i]);
	puts("");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
