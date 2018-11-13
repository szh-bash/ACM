#include <queue>
#include <vector> 
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 100000
#define M 500000
#define INF 999999999
#define num(x) ((x)>='0' && (x)<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, cnt, m, st, ed, flag[N], nex[M], nu[M], va[M], dist[N];
struct node{
	int n, dist;
	node (int n, int dist): n(n), dist(dist){}
	bool operator <(const node &o) const {return this->dist<o.dist;}
	bool operator >(const node &o) const {return this->dist>o.dist;} 
};
//priority_queue<int> qq;//这是个大猪蹄子，大根堆 
//typedef pair<int, int> P; 
//priority_queue<P, vector<P>, greater<P> > Q; pair按字典序比较 
priority_queue<node, vector<node>, greater<node> > q;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (!num(ch)) (ch=='-'?q=-1:0), ch=getchar();
	while (num(ch)) p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v, int w){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;va[cnt]=w;
}
void dijkstra(){
	for (int i=1;i<=n;i++) dist[i]=INF, flag[i]=0;
	dist[st]=0;
	q.push(node(st,0));
	while (!q.empty()){
		node curNode=q.top();
		q.pop();
		int u=curNode.n;
		flag[u]=1;
		for (int j=nex[u];j;j=nex[j]){
			int v=nu[j];
			if (!flag[v] && dist[u]+va[j]<dist[v])
				dist[v]=dist[u]+va[j],
				q.push(node(v,dist[v]));
		}
		while (!q.empty() && flag[q.top().n]) q.pop();
	}
}
int main(){
	cnt=n=read();m=read();
	st=read();ed=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read(), w=read();
		add(u, v, w);
		add(v, u, w);
	}
	dijkstra();
	cout<<dist[ed]<<endl;
	return 0;
}
