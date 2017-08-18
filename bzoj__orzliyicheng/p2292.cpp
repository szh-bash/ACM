#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define Pi pair<int,int>
#define Px first
#define Py second
using namespace std;
const int MAXN=250000;
const int MAXM=2005000;
int N,M,tot,v[MAXM],next[MAXM],point[MAXN],k,ans;
bool vis[MAXN];
inline void add(int x,int y){
	v[++tot]=y; next[tot]=point[x]; point[x]=tot;
}
void bfs()
{
	queue<Pi> q; q.push(Pi(1,0)); vis[1]=true;
	while(!q.empty()){
		Pi now=q.front(); q.pop();
		for(int mp=point[now.Px];mp;mp=next[mp])
		  if(!vis[v[mp]])
		  {
		  	vis[v[mp]]=true; q.push(Pi(v[mp],now.Py+1));
		  	if(v[mp]==N) {
		  		ans=now.Py+1; return;
		  	}
		  }
	}
	
}
int main()
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;++i){
		int x,y,c; scanf("%d%d%d",&x,&y,&c);
		if(c==1) add(x,y);
		else{
			++k; add(x,N+k); add(N+k,y);
		}
	}
	bfs();
	printf("%d\n",ans);
	return 0;
}
