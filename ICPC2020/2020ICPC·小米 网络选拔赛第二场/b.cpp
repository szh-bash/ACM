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
#define D 4
#define getx(x) (((x)-1)/m+1)
#define gety(x) (((x)-1)%m+1)
#define hash(x,y) ((((x)-1)*m+(y))*(x>0)*(y>0))
#define S 1000005
int dx[]={0,1,0,-1};
ll ux[S], uy[S], dox[S], doy[S], sum[S], f[S];
int n, m, ct, cnt, q[S], flag[S], lx, rx ,ly, ry, xx[S][3], yy[S][3], a[S];
void dfs(int x){
	flag[x]=1;
	lx=min(lx,getx(x));
	rx=max(rx,getx(x));
	ly=min(ly,gety(x));
	ry=max(ry,gety(x));
	for (int j=0;j<D;j++)
		if (x+dx[j]>0 && x+dx[j]<=cnt && !flag[x+dx[j]] && a[x+dx[j]]==a[x])
			dfs(x+dx[j]);
}
void upd(int mode, int y){
	for (int i=1;i<=ct;i++)
		f[hash(xx[q[i]][mode],yy[q[i]][mode])] += q[i]*y;
}
ll getsum(int x1, int y1, int x2, int y2){
	if (x1>x2) swap(x1,x2);
	if (y1>y2) swap(y1,y2);
	return sum[hash(x2,y2)]-sum[hash(x2,y1-1)]-sum[hash(x1-1,y2)]+sum[hash(x1-1,y1-1)];
}
void solve(){
	cnt=n*m;
	dx[0]=-m;dx[2]=+m;
	for (int i=1;i<=cnt;i++) a[i]=read(), flag[i]=0;
	ct=0;
	ll all=0;
	for (int i=1;i<=cnt;i++)
		if (!flag[i]) 
			q[++ct]=a[i],
			all+=a[i],
			lx=m+1,
			ly=n+1,
			rx=ry=0,
			dfs(i),
			xx[a[i]][1]=lx, yy[a[i]][1]=ly,
			xx[a[i]][2]=rx, yy[a[i]][2]=ry;
	
	upd(2,1);
	ux[0]=uy[0]=0;
	for (int i=1;i<=n;i++){
		ux[i]=ux[i-1];
		for (int j=1;j<=m;j++)
			ux[i]+=f[hash(i,j)];
	}
	for (int j=1;j<=m;j++){
		uy[j]=uy[j-1];
		for (int i=1;i<=n;i++)
			uy[j]+=f[hash(i,j)];
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			sum[hash(i,j)]=f[hash(i,j)]+sum[hash(i-1,j)]+sum[hash(i,j-1)]-sum[hash(i-1,j-1)];
	upd(2,-1);
	upd(1,1);
	dox[n+1]=doy[m+1]=0;
	for (int i=n;i;i--){
		dox[i]=dox[i+1];
		for (int j=1;j<=m;j++)
			dox[i]+=f[hash(i,j)];
	}
	for (int j=m;j;j--){
		doy[j]=doy[j+1];
		for (int i=1;i<=n;i++)
			doy[j]+=f[hash(i,j)];
	}
	upd(1,-1);
	ll ans=0;
	for (int i=1;i<=ct;i++){
		int x=q[i];
		cout<<"x1,y1: "<<xx[x][1]<<' '<<yy[x][1]<<endl;
		cout<<"x2,y2: "<<xx[x][2]<<' '<<yy[x][2]<<endl;
		ll s=ux[xx[x][1]-1]+dox[xx[x][2]+1]+uy[yy[x][1]-1]+doy[yy[x][2]+1];
		cout<<s<<endl;
		s-=getsum(xx[x][1]-1, yy[x][1]-1, 1, 1);
		cout<<s<<endl;
		s-=getsum(xx[x][1]-1, yy[x][2]+1, 1, m);
		cout<<s<<endl;
		s-=getsum(xx[x][2]+1, yy[x][1]-1, n, 1);
		cout<<s<<endl;
		s-=getsum(xx[x][2]+1, yy[x][2]+1, n, m);
		cout<<s<<endl;
		s+=getsum(xx[x][1], yy[x][1], xx[x][2], yy[x][2]);
		cout<<x<<' '<<s<<' '<<all<<endl;
		ans += (all-s)^x; 
	}
	printf("%lld\n", ans);
}
int main(){
	while (~scanf("%d%d", &n, &m)) solve();
    return 0;
}
