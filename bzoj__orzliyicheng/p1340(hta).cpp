#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#define x first
#define y second
using namespace std;
inline int get()
{
    int f=0,v=0;char ch;
    while(!isdigit(ch=getchar()))if(ch=='-')break;
    if(ch=='-')f=1;else v=ch-'0';
    while(isdigit(ch=getchar()))v=v*10+ch-'0';
    if(f==1)return -v;else return v;
}
const int maxn=555,maxm=130000,inf=1000000000;
int n,H,Link[maxn],tot=0,s[maxn],h[maxn],source,sink;
struct Tedge
{
	int t,v,op,pre;
	Tedge(){}
	Tedge(int _t,int _v,int _op,int _pre){t=_t,v=_v,op=_op,pre=_pre;}
}g[maxm];
pair<int,int> a[maxn];
inline void add(int s,int t,int v)
{
	int tp;
	tp=Link[s]; Link[s]=++tot; g[tot]=Tedge(t,v,tot+1,tp);
	tp=Link[t]; Link[t]=++tot; g[tot]=Tedge(s,0,tot-1,tp);
}
inline bool bfs()
{
	for(int i=1;i<=sink;i++)h[i]=-1;
	int front=0,rear=1;
	s[front]=source,h[source]=1;
	while(front!=rear)
	{
		int p=s[front];
		for(int i=Link[p];i;i=g[i].pre)
			if(h[g[i].t]==-1&&g[i].v)h[g[i].t]=h[p]+1,s[rear++]=g[i].t;
		front++;
	}
	return h[sink]!=-1;
}
inline int aug(int x,int flow)
{
	if(x==sink)return flow;
	int tp=flow,d;
	for(int i=Link[x];i;i=g[i].pre)
	{
		if(h[g[i].t]!=h[x]+1||g[i].v<=0)continue;
		d=min(tp,g[i].v),d=aug(g[i].t,d);
		g[i].v-=d,g[g[i].op].v+=d,tp-=d;
		if(tp==0)break;
	}
	if(tp==flow)h[x]=-1;
	return flow-tp;
}
int main()
{
	get(),H=get(),n=get();
	source=2*n+1,sink=source+1;
	for(int i=1;i<=n;i++)
	{
		int x=get(),y=get();
		a[i]=make_pair(x,y);
		if(y<=100)add(source,i,inf);
		if(H-y<=100)add(i+n,sink,inf);
		add(i,i+n,1);
	}
	typedef long long LL;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(LL(a[i].x-a[j].x)*(a[i].x-a[j].x)+LL(a[i].y-a[j].y)*(a[i].y-a[j].y)<=40000)add(i+n,j,inf),add(j+n,i,inf);
	int ans=0;
	while(bfs())ans+=aug(source,inf);
	printf("%d\n",ans);
	return 0;
}
