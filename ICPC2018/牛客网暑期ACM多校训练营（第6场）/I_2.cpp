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
#define N 800000
#define M 8000000
#define mo 998244353
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, x, cnt, ct, countt, root, ls[M], rs[M], g[M], ans[N], ansm[N], q[M];
ll res;
struct lyk{
	int l, r, n;
}p[N], a[M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
bool cmpL(lyk a, lyk b) { return a.l<b.l;}
bool cmpR(lyk a, lyk b) { return a.r<b.r;}
void build(int &t, int l, int r){
	if (!t) t=++cnt;
	ls[t]=rs[t]=0;
	int mid=l+r>>1;
	g[t]=ct+1;
	q[t]=r-l+1;
	for (int i=l;i<=r;i++)	a[++ct]=p[i];
	sort(a+g[t],a+g[t]+r-l+1,cmpR);
	if (l==r) return;
	build(ls[t],l,mid);
	build(rs[t],mid+1,r);
}
void work(int t, int l, int r, int now){
	if (p[r].l<=x){
		int i;
		for (i=1;i<=q[t];i++){
			lyk v=a[g[t]+q[t]-i];
			if (v.r>=x){
				if (ans[v.n]) continue;
				ans[v.n]=now;
				res=res*v.n%mo;
				countt++;
			}
			else break;
		}
		q[t]-=i-1;
		return;			
	}
	else if (l==r) return;
	int mid=l+r>>1;
	work(ls[t],l,mid,now);
	if (p[mid+1].l<=x) work(rs[t],mid+1,r,now);
}
int main(){
	for (int _=read(), __=1;_;_--, __++){
		cnt=ct=root=0;
		n=read();m=read();
		for (int i=1;i<=n;i++)
			p[i].l=read(),
			p[i].r=read(),
			p[i].n=i,
			ans[i]=0;
		sort(p+1,p+1+n,cmpL);
		build(root,1,n);
		res=0;
		for (int i=1;i<=m;i++){
			x=read()^res;
			res=1;
			countt=0;
			work(1,1,n,i);
			if (!countt) res=0;
			ansm[i]=countt;
		}
		cout<<"Case #"<<__<<":"<<endl;
		for (int i=1;i<=m;i++)
			printf("%d\n", ansm[i]);
		for (int i=1;i<=n;i++)
			printf("%d ", ans[i]);cout<<endl;
	}
    return 0;
}
