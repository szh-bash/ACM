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
#define N 80000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, cnt, ct, g[20], f[N], v[N], a[N][20], flag[N][20];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void work(int u, int V){
	int mau=0, mav=0, p;
	for (int i=1;i<=n;i++){
		if (flag[u][i]) mau=max(mau,a[u][i]);
		if (flag[V][i]) mav=max(mav,a[V][i]);
	}
	if (mau<mav) {
		swap(u,V);
		swap(mau,mav);
	}
	for (int i=1;i<=n;i++)
		if (flag[u][i] && a[u][i]>mav && a[u][i]<=mau)
			mau=a[u][i],
			p=i;
	flag[u][p]=0;
	v[++ct]=u;
}
int main(){
	g[0]=1;
	for (int i=1;i<=15;i++) g[i]=g[i-1]<<1;
	for (int _=read(), k=1;_;_--, k++){
		n=read();
		for (int i=1;i<=g[n];i++)
			for (int j=1;j<=n;j++){
				a[i][j]=read(),
				flag[i][j]=1;
				//cout<<i<<' '<<j<<' '<<a[i][j]<<endl;
			}
		cnt=g[n];
		for (int i=1;i<=g[n];i++) v[i]=i;
		for (int i=1;i<=n;i++){
			ct=0;
			for (int j=1;j<=cnt;j+=2)
				work(v[j],v[j+1]);
			cnt=ct;
		}
		cout<<"Case #"<<k<<": "<<v[1]<<endl;
	}
    return 0;
}
