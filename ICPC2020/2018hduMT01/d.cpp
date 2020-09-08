#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define M 200005
#define N 800005
struct node{
	int n, x;
	node(){};
	node (int n, int x):n(n), x(x){};
	bool operator <(const node &o) const {return this->x<o.x;}
	bool operator >(const node &o) const {return this->x>o.x;}
}l[M];
priority_queue<node, vector<node>, greater<node> > q;
int g[N];
void build(int t, int l, int r){
	if (l==r) {
		g[t]=0;
		return;
	}
	int mid=l+r>>1;
	build(t<<1, l, mid);
	build((t<<1)+1, mid+1, r);
	g[t]=min(g[t<<1], g[(t<<1)+1]);
}
int query(int t, int l, int r, int x){
	if (l==r) return l;
	int mid=l+r>>1;
	if (g[t<<1]<x) return query(t<<1, l, mid, x);
	return query((t<<1)+1, mid+1, r, x);
}
void upd(int t, int l, int r, int x, int y){
	if (l==r){
		g[t]=y;
		return;
	}
	int mid=l+r>>1;
	if (x<=mid) upd(t<<1, l, mid, x, y);
	else upd((t<<1)+1, mid+1, r, x, y);
	g[t]=min(g[t<<1], g[(t<<1)+1]);
}
int n, m, cnt, flag[M];
void solve(){
	n=read();m=read();
	cnt=0;
	for (int i=1;i<=m;i++){
		l[++cnt].n=i;
		l[cnt].x=read();
		l[++cnt].n=-i;
		l[cnt].x=read()+1;
		flag[i]=0;
	}
	sort(l+1, l+1+cnt);
	build(1,1,n);
	for (int i=1, j=1;i<=n;i++){
		while (l[j].x==i && j<=cnt){
			if (l[j].n>0) q.push(node(l[j].n,l[j].x));
			else flag[-l[j].n]=1;
			j++;
		}
		node top=!q.empty()?q.top():node(0,0);
		while (!q.empty() && flag[top.n]){
			q.pop();
			if (!q.empty()) top=q.top();
		}
		if (q.empty()){
			printf("1%s", (i==n?"\n":" "));
			continue;
		}
		int ans=query(1,1,n,top.x);
		upd(1,1,n,ans,i);
		printf("%d%s", ans, (i==n?"\n":" "));
	}
	while (!q.empty()) q.pop();
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
