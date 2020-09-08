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
#define M 200000
struct node{
	int n, x;
}l[M];
bool cmp(node a, node b){
	if (a.x>b.x) return 1;
	if (a.x<b.x) return 0;
	return a.n<b.n;
}
int n, m, ct, a[M], b[M];
void solve(){
	n=read();m=read();
	ct=0;
	for (int i=1;i<=m;i++)
		++ct,
		l[ct].n=i,
		a[i]=l[ct].x=read(),
		++ct,
		l[ct].n=-i,
		b[i]=l[ct].x=read();
	sort(l+1,l+1+ct,cmp);
	ll ans=0;
	ll sum=0;
	int p=0;
	for (int i=1;i<=m;i++) ans=max(ans,1ll*(n-1)*b[i]+a[i]);
	for (int i=1;i<=ct;i++)
		if (l[i].n>0){
			if (p<n) sum+=l[i].x, p++;
		}
		else{
			int t=a[-l[i].n]<=l[i].x;
			if (p<n) ans=max(ans,sum+1ll*(n-t-p)*l[i].x+a[-l[i].n]*t);
		}
	cout<<max(ans,sum)<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
