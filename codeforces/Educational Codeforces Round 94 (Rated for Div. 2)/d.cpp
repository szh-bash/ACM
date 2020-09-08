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
#define N 3005
#define M N*N
struct node{
	int x, p;
}l[M];
int n, a[N], c[N];
inline void add(int n, int x, int p){
	l[n].x=x;
	l[n].p=p;
}
bool cmp(node a, node b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.p>b.p;
}
void upd(int x, int y){
	for (;x<=n;x+=x&(-x)) c[x]+=y;
}
ll sum(int x){
	ll res=0;
	for (;x;x-=x&(-x)) res+=c[x];
	return res;
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int ct=0;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (a[i]==a[j]){
				add(++ct,i,0);
				add(++ct,j,i);
			} 
	sort(l+1,l+1+ct,cmp);
	ll ans=0;
	for (int i=1;i<=ct;i++)
		if (!l[i].p) upd(l[i].x,1);
		else upd(l[i].p,-1), ans+=sum(l[i].x-1)-sum(l[i].p);
	printf("%I64d\n", ans);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
