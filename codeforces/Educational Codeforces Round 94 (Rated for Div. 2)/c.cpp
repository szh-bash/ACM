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
char s[200005], ans[200005];
void solve(){
	scanf("%s", s+1);
	int x=read(), n=strlen(s+1);
	int flag=0;
	for (int i=1;i<=n;i++)
		if (i+x<=n && s[i+x]=='0' || i>x && s[i-x]=='0') ans[i]='0';
		else ans[i]='1';
	for (int i=1;i<=n;i++)
		if (s[i]=='1'){
			if (i+x<=n && ans[i+x]=='1' || i>x && ans[i-x]=='1') continue;
			flag=1;
			break;
		}
	ans[n+1]=0;
	if (flag) puts("-1");else 
	puts(ans+1);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
