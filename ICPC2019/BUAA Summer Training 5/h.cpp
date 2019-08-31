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
#define N 200005
#define M (N*30)
#define inf 100001
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
#define eps 1e-8
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, cnt, h[N], root[N];
ll pre[N];
int l[M], r[M];
ll s[M], are[M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
double sum;
bool check(int u, int v, double h){
	int le=0, ri=inf-1;
	double tmp=0;
	int ts=0;
	while (le!=ri){
		int mid=le+ri>>1;
		if (h>mid)
			le=mid+1,
			u=r[u],
			v=r[v];
		else
			tmp+=are[r[u]]-s[r[u]]*h,
			tmp-=are[r[v]]-s[r[v]]*h,
			ts+=s[r[u]]-s[r[v]],
			ri=mid,
			u=l[u],
			v=l[v];
	}
	if (le>=h) tmp+=are[u]-s[u]*h, tmp-=are[v]-s[v]*h;
//	cout<<h<<' '<<tmp<<' '<<sum<<' '<<ts<<endl;
	return tmp>=sum;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++){
		h[i]=read(), pre[i]=pre[i-1]+h[i];
		int u=root[i-1], v=root[i]=++cnt, le=0, ri=inf-1;
		s[v]=s[u]+1;
		are[v]=are[u]+h[i];
		while (le!=ri){
			int mid=le+ri>>1;
			if (h[i]<=mid) 
				r[v]=r[u],
				l[v]=++cnt,
				v=l[v],
				u=l[u],
				ri=mid;
			else
				l[v]=l[u],
				r[v]=++cnt,
				v=r[v],
				u=r[u],
				le=mid+1;
			s[v]=s[u]+1;
			are[v]=are[u]+h[i];
		}
	}
	for (int i=1;i<=m;i++){
		int u=read()-1, v=read(), x=read(), y=read();
		sum=(double)(pre[v]-pre[u])*x/y;
//		cout<<sum<<endl;
		u=root[u];v=root[v];
		double ll=0, rr=inf;
		while (rr-ll>eps){
			double mid=(ll+rr)/2;
//			cout<<ll<<' '<<rr<<' ';
			if (check(v,u,mid)) ll=mid;
			else rr=mid;
		}
		printf("%.8lf\n", ll);
	}
    return 0;
}
