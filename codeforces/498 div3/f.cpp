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
typedef unsigned long long ll;
using namespace std;
int n, m, t, ct1, ct2;
ll a[50][50], k, ans;
map <ll, int> f;
struct qlz{
	int x;
	ll q;
}l1[3000000], l2[3000000];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void dfs1(int x, int y, ll q){
	if (x>n || y>m || !x || !y) return;
	q^=a[x][y];
	if (x+y==t+1){
		l1[++ct1].x=x;
		l1[ct1].q=q;
		return;
	}
	dfs1(x+1,y,q);
	dfs1(x,y+1,q);
}
void dfs2(int x, int y, ll q){
	if (!x || !y) return;
	q^=a[x][y];
	if (x+y==t+1){
		l2[++ct2].x=x;
		l2[ct2].q=q;
		return;
	}
	dfs2(x-1,y,q);
	dfs2(x,y-1,q);
}
bool cmp(qlz a, qlz b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.q<b.q;
}
int main(){
	n=read();m=read();cin>>k;
	t=min(n,m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) cin>>a[i][j];
	dfs1(1,1,0);
	dfs2(n,m,0);
	sort(l1+1,l1+1+ct1,cmp);
	sort(l2+1,l2+1+ct2,cmp);
	for (int i=1, j=1, e=1, o;e<=t;e++, i=o){
		f.clear();		
		for (o=i;o<=ct1 && l1[o].x==e;o++) f[l1[o].q]=f[l1[o].q]+1;
		for (;j<=ct2 && l2[j].x==e;j++) ans+=f[l2[j].q^k^a[e][t+1-e]];
	}
	cout<<ans<<endl;
	return 0;
}
