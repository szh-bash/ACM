#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 500000
#define INF 2000000100
typedef long long ll;
using namespace std;
struct qlz{
	ll t, u, v, x, l, r;
	int flag;
}l[N], f[N], q[N];
ll cnt, n, m, bt, ic, damage, maxh[N], hp[N], re[N], op[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
bool cmp(qlz a, qlz b){return a.t<b.t;}
bool cmp2(qlz a, qlz b){return a.x<b.x;}
int main(){
	cin>>n>>m;
	cin>>bt>>ic>>damage;
	for (int i=1;i<=n;i++){
		maxh[i]=read(), hp[i]=read(), re[i]=read();
		q[i].l=0;
		q[i].v=i;
		if (!re[i])
			if (hp[i]>damage) q[i].r=0;else q[i].r=INF;
		else
			if (hp[i]>damage) q[i].r=0;
			else
				if (maxh[i]<=damage) q[i].r=INF;
				else q[i].r=(damage-hp[i])/re[i]+1;
		op[i]=i;
	}
	for (int i=1;i<=m;i++)
		l[i].t=read(), l[i].u=read(), l[i].v=read();
	sort(l+1,l+1+m,cmp);
	for (int i=1;i<=m;i++){
		ll u=l[i].u, v=l[i].v, t=l[i].t;
		q[i+n].v=u;
		q[i+n].l=t;
		q[op[u]].r=min(q[op[u]].r,t);
		if (!re[u])
			if (v>damage) q[i+n].r=t;else q[i+n].r=INF;
		else
			if (v>damage) q[i+n].r=t;
			else
				if (maxh[u]<=damage) q[i+n].r=INF;
				else q[i+n].r=t+(damage-v)/re[u]+1;
		op[u]=i+n;
	}
	for (int i=1;i<=n+m;i++){
		if (q[i].r==INF && ic){
			cout<<-1<<endl;
			return 0;
		}
		f[++cnt].x=q[i].l;f[cnt].flag=1;
		f[++cnt].x=q[i].r;f[cnt].flag=-1;
	}
	sort(f+1,f+1+cnt,cmp2);
	ll ans=0, tot=0;
	for (int i=1;i<=cnt;i++)
		if (f[i].x==f[i-1].x) tot+=f[i].flag;
		else {
			ans=max(ans,tot*(bt+ic*(f[i].x-1)));
			tot+=f[i].flag;
		}
	cout<<ans<<endl;
	return 0;
}
