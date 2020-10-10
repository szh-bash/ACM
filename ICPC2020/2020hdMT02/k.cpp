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
#define N 300005
struct nodel{
	int n, s, t, x;
}l[N], p[N];
bool cmp(nodel a, nodel b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.t>b.t;
}
bool cmpp(nodel a, nodel b){return a.s<b.s;}
struct node{
	int n, dist;
	node (int n, int dist): n(n), dist(dist){}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;} 
};
priority_queue<node, vector<node>, greater<node> > q;
int n, flag[N];
ll ans[N];
void solve(){
	n=read();
	for (int i=1;i<=n;i++){
		int u=read(), v=read();
		l[i].n=p[i].n=i;
		l[i].s=p[i].s=u;
		l[i].t=p[i].t=v;
		l[i].x=p[i].x=u+v;
		flag[i]=0;
	}
	sort(l+1,l+1+n,cmp);
	sort(p+1,p+1+n,cmpp);
	ll x=0;
	for (int i=1, j=1, ct=0;i<=n;){
		while (i<=n && flag[l[i].n]) i++;
		if (i<=n)
			flag[l[i].n]=1,
			ans[++ct]=l[i].x,
			x=l[i++].x;
		while (j<=n && p[j].s<x){
			if (flag[p[j].n]) {j++;continue;}
			q.push(node(p[j].n,p[j].t));
			flag[p[j++].n]=1;
		}
		while (!q.empty()){
			node top=q.top();
			while (i<=n && flag[l[i].n]) i++;
			if (i>n || top.dist+x<l[i].x || top.dist+x==l[i].x && top.dist>l[i].t){
				x+=top.dist; ans[++ct]=x; q.pop();
				while (j<=n && p[j].s<x){
					if (flag[p[j].n]) {j++;continue;}
					q.push(node(p[j].n,p[j].t));
					flag[p[j++].n]=1;
				}
			}
			else break;
		}
	}
	for (int i=1;i<=n;i++) printf("%I64d%s", ans[i], i==n?"\n":" ");
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
