#include <queue>
#include <vector> 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 100000
#define M 9000000
#define num(x) ((x)>='0' && (x)<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
typedef pair<int, int> P; 
const ll INF =(ll)999999999*99999999;
int n, cnt, m, st, ed, a[N], flag[N];
ll dist[N];
struct node{
	int n;
	ll dist;
	node (int n, ll dist): n(n), dist(dist){}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;} 
};
//priority_queue<P, vector<P>, greater<P> > Q; pair°´×ÖµäÐò±È½Ï 
priority_queue<node, vector<node>, greater<node> > q;
//priority_queue<node> q; not greater! 
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (!num(ch)) (ch=='-'?q=-1:0), ch=getchar();
	while (num(ch)) p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void dijkstra(){
	for (int i=0;i<a[1];i++) dist[i]=INF, flag[i]=0;
	dist[0]=0;
	q.push(node(0,0));
	while (!q.empty()){
		node curNode=q.top();
		q.pop();
		int u=curNode.n;
		flag[u]=1;
		for (int j=2;j<=n;j++)
			if (!flag[(a[j]+u)%a[1]] && dist[u]+a[j]<dist[(a[j]+u)%a[1]])
				dist[(a[j]+u)%a[1]]=dist[u]+a[j],
				q.push(node((a[j]+u)%a[1],dist[(a[j]+u)%a[1]]));
		while (!q.empty() && flag[q.top().n]) q.pop();
	}
}
int main(){
	cnt=n=read();
	st=0;
	for (int i=1;i<=n;i++) a[i]=read();
	dijkstra();
	for (int _=read(), ed;_;_--) 
		ed=read(),
		printf("%s\n", dist[ed%a[1]]<=ed?"TAK":"NIE");
	return 0;
}
