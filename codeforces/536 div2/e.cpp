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
#define N 500000
#define M 500000
typedef long long ll;
using namespace std;
int cnt, n, m, k, d[N], flag[N];
ll w[N];
int target[N];
struct njh{
	int x, y, n;
}l[M];
ll f[100005][205], g[3][205];
struct node{
	int n, w, d;
	node (int n, int w, int d): n(n), w(w), d(d){}
	bool operator <(const node &o) const {
		if (this->w<o.w) return 1;
		if (this->w>o.w) return 0;
		return this->d<o.d;
	}
	bool operator >(const node &o) const {
		if (this->w>o.w) return 1;
		if (this->w<o.w) return 0;
		return this->d>o.d;
	}
};
priority_queue<node, vector<node>, less<node> > q;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(njh a, njh b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.y>b.y;
}
int main(){
	n=read();m=read();k=read();
	for (int i=1;i<=k;i++){
		int s, t;
		s=read();
		t=read();
		d[i]=read();
		w[i]=read();
		l[++cnt].x=s;
		l[cnt].y=1;
		l[cnt].n=i;
		l[++cnt].x=t+1;
		l[cnt].y=-1;
		l[cnt].n=i;
	}
	sort(l+1,l+1+cnt,cmp);
	int j=1;
	for (int i=1;i<=n;i++){
		while (j<=cnt && l[j].x<=i){
			int v=l[j].n;
			if (l[j].y>0){
				flag[v]=1;
				q.push(node(v,w[v],d[v]));
			}
			else{
				flag[v]=0;
			}
			j++;
		}
		node v=q.empty()?node(0,0,0):q.top();
		while (!q.empty() && !flag[v.n]) q.pop(), v=q.empty()?node(0,0,0):q.top();
		target[i]=v.n;
	}
	for (int i=n, o=0;i;i--, o^=1)
		for (int j=0;j<=m;j++){
			if (!target[i]) f[i][j]=f[i+1][j];
			else f[i][j]=w[target[i]]+f[d[target[i]]+1][j];
			g[o][j]=min(j?g[o^1][j-1]:f[i][j],f[i][j]);
			f[i][j]=g[o][j];
		}
	cout<<f[1][m]<<endl;
	return 0; 
}
