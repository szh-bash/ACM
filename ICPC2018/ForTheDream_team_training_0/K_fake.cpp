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
#define N 500000
#define M 1000000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
#define ls (t<<1)
#define rs ((t<<1)+1)
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n;
int g[N];
int p[N], q[N], bit[N];
int nex0[N], pre0[N], nex1[N], pre1[N];
int f[M], tag[M];
char s[N], s0[N], s1[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void build(int t, int l, int r){
	f[t]=mo;
	tag[t]=0;
	if (l==r) return ;
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
}
void add(int &a, int b){
	a=a+b>mo?mo:a+b;
}
void pushdown(int t){
	if (tag[t]){
		add(f[ls],tag[t]);
		add(tag[ls],tag[t]);
		add(f[rs],tag[t]);
		add(tag[rs],tag[t]);
		tag[t]=0;
	}
}
void update(int t){
	f[t]=min(f[ls],f[rs]);
}
void sett(int t, int l, int r, int x, int y){
	if (l==r){
		f[t]=y;
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	if (x<=mid) sett(ls,l,mid,x,y);
	else sett(rs,mid+1,r,x,y);
	update(t);
}
void upd(int t, int l, int r, int x, int y){
	if (r<=x){
		add(f[t],y);
		add(tag[t],y);
		return;
	}
	pushdown(t);
	int mid=l+r>>1;
	upd(ls,l,mid,x,y);
	if (x>mid) upd(rs,mid+1,r,x,y);
	update(t);
}
int query(int t, int l, int r, int x){
	if (r<=x) return f[t];
	pushdown(t);
	int mid=l+r>>1;
	int p0=query(ls,l,mid,x), p1=mo;
	if (x>mid) p1=query(rs,mid+1,r,x);
	return min(p0,p1);
}
int main(){
	//freopen("std.in","r",stdin);
	bit[0]=1;
	for (int i=1;i<N;i++) bit[i]=(bit[i-1]<<1)>mo?mo:(bit[i-1]<<1);
	for (int _=read();_;_--){
		n=read()+1;
		scanf("%s%s%s", s+1, s0+1, s1+1);
		s[n]=s0[n]=s1[n]='0';
		int pi0=n, pi1=n;
		for (int i=n;i;i--){
			if (s0[i]=='0') pi0=i;
			if (s1[i]=='0') pi1=i;
			nex0[i]=pi0;
			nex1[i]=pi1;
		}
		pi0=0, pi1=0;
		for (int i=1;i<=n;i++){
			if (s0[i]=='0') pi0=i;
			if (s1[i]=='0') pi1=i;
			pre0[i]=pi0;
			pre1[i]=pi1;
		}
		for (int i=1;i<=n;i++)
			if (s0[i]=='0') p[i]=1;
			else{
				if (pre0[i]) p[i]=bit[i-pre0[i]];else p[i]=mo;
				//continue; 
				if (!pre1[i]) continue;
				ll u=bit[i-pre1[i]], v=bit[nex0[i]-i]-1;
				p[i]=min(p[i],(int)(u*v>mo?mo:u*v+1));
			}
		for (int i=1;i<=n;i++)
			if (s1[i]=='0') q[i]=1;
			else{
				if (pre1[i]) q[i]=bit[i-pre1[i]];else q[i]=mo;
				//continue;
				if (!pre0[i]) continue;
				ll u=bit[i-pre0[i]], v=bit[nex1[i]-i]-1;
				q[i]=min(q[i],(int)(u*v>mo?mo:u*v+1));
			}
		build(1,1,n);
		for (int i=1;i<=n;i++)
			if (s[i]=='1'){
				g[i]=(g[i-1]+p[i])>mo?mo:(g[i-1]+p[i]);
				int qq=0, mi=mo;
				for (int j=i+1;j<=n && s[j]=='0' && qq<mo;j++){
					mi=min(mi,qq+p[j]);
					qq+=q[j];
				}
				if (g[i-1]+q[i]<mo) sett(1,1,n,i,g[i-1]+q[i]);
				if (mi<mo) g[i]=min(g[i],query(1,1,n,i)+mi);
			}
			else
				g[i]=g[i-1],
				upd(1,1,n,i,q[i]);
		cout<<g[n]<<endl;
	}
    return 0;
}
