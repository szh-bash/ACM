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
void solve(){
	int p=read(), f=read();
	int a=read(), b=read();
	int s=read(), w=read();
	if (s>w) swap(s,w), swap(a,b);
	int pa=min(p/s,a);
	int fa=min(f/s,a-pa);
	if (a>pa+fa){
		printf("%d\n", pa+fa);
		return;
	}
	int ans=0;
	for (int i=max(0,a-f/s);i<=pa;i++)
		ans=max(a+min(b,(p-i*s)/w+(f-(a-i)*s)/w),ans);
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
