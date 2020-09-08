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
#define N 200005
int n, cnt, ans[N];
char a[N], b[N];
void work(char *s){
	for (int i=1;i<n;i++)
		if (s[i-1]!=s[i]) ans[++cnt]=i;
	if (s[n-1]=='1') ans[++cnt]=n;
}
void solve(){
	n=read();
	scanf("%s%s", a, b);
	cnt=0;
	work(a);
	int res=cnt;
	work(b);
	printf("%d", cnt);
	for (int i=1;i<=res;i++) printf(" %d", ans[i]);
	for (int i=cnt;i>res;i--) printf(" %d", ans[i]);
	puts("");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
