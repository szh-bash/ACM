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
#define mo 998244353
#define num(x) ((x)>='0' && (x)<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
#define S 1000000
char s[S];
int dex;
int read(){
    int p=0, q=1;
    while (s[dex] && !num(s[dex])) s[dex++]=='-'?q=-1:0;
    while (s[dex] && num(s[dex])) p=p*10+s[dex++]-'0';
    return p*q;
}
#define N 205
int n, nn, m, k, x[N], y[N], a[N][N], c[N][N], b[N][N], d[N];
void inc(int &a, int b){
	if (a+b>=mo) a=a+b-mo;
	else a=a+b;
}
int mul(int a, int b){
	if (1ll*a*b>=mo) return 1ll*a*b%mo;
	return a*b;
}
void add(int u, int v, int w){
	a[u][v]=w;
}
int power(int a, int b){
	int c=1;
	while (b){
		if (b&1) c=mul(a,c);
		a=mul(a,a);
		b>>=1;
	}
	return c;
}
void ksm(int k){
	while (k){
		if (k&1){
			for (int i=1;i<=nn;i++){
				y[i]=0;
				for (int j=1;j<=nn;j++)
					inc(y[i],mul(x[j],a[j][i]));
			}
			for (int i=1;i<=nn;i++) x[i]=y[i];
		}
		for (int i=1;i<=nn;i++)
			for (int j=1;j<=nn;j++){
				c[i][j]=0;
				for (int k=1;k<=nn;k++)
					inc(c[i][j],mul(a[i][k],a[k][j]));
			}
		for (int i=1;i<=nn;i++)
			for (int j=1;j<=nn;j++)
				a[i][j]=c[i][j];
		k>>=1;
	}
}
void solve(){
	n=read(), m=read(), k=read();
	for (int i=1;i<=n*2;i++)
		for (int j=1;j<=n*2;j++)
			a[i][j]=0,
			b[i][j]=-1;
	for (int i=1;i<=n;i++) d[i]=0;
	for (int i=1;i<=m;i++){
		int u=read(), v=read(), w=read();
		b[u][v]=b[v][u]=w;
		d[u]++;
		d[v]++;
	}
	for (int i=1;i<=n;i++){
		int p=power(d[i],mo-2);
		for (int j=1;j<=n;j++)
			if (b[i][j]>0){
				add(i*2-1,j*2,p);
				add(i*2,j*2-1,p);
			}
			else if (b[i][j]>-1){
				add(i*2-1,j*2-1,p);
				add(i*2,j*2,p);
			}
	}
	nn=n*2;
	x[2]=1;
	ksm(k);
	cout<<x[nn-1]<<endl;
}
int main(){
	fread(s,1,S,stdin);
	for (int _=read();_;_--) solve();
    return 0;
}
