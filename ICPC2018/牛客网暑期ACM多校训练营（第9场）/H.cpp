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
#define M 110000
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
struct qlz{
	int x, y, tp;
}l[M];
int g[M], f[M], cnt, block, n, m, k, sum[41][M];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(int &a, int b){
	if (a+b>=mo) a=a+b-mo;else a=a+b;
}
int power(ll a, int b){
	ll c=1;
	while(b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	f[0]=1;
	n=read();m=read();k=read();
	for (int i=1;i<=n+k;i++) f[i]=(ll)f[i-1]*i%mo;
	int invk=power(f[k-1],mo-2);
	for (int i=0;i<=n;i++)
		g[i]=(ll)f[i+k-1]*power(f[i],mo-2)%mo*invk%mo;
	for (int i=1;i<=m;i++){
		l[i].tp=read();
		if (!l[i].tp) l[i].x=read(), l[i].y=read();
		else l[i].x=read();
	}
	block=sqrt(n*k);
	cnt=m/block;
	if (cnt*block<m) cnt++;
	for (int i=1;i<=cnt;i++){
		int u=(i-1)*block;
		for (int j=1;j<=block;j++)
			if (u+j<=m)
				if (l[u+j].tp){
					int answer=sum[k][l[u+j].x];
					for (int k=1;k<j;k++)
						if (!l[u+k].tp && l[u+k].x<=l[u+j].x)
							upd(answer,(ll)g[l[u+j].x-l[u+k].x]*l[u+k].y%mo);
					printf("%d\n", answer);
				}
				else upd(sum[0][l[u+j].x],l[u+j].y);
		for (int j=1;j<=k;j++)
			for (int q=1;q<=n;q++)
				upd(sum[j][q],-sum[j][q]),
				upd(sum[j][q],sum[j-1][q]),
				upd(sum[j][q],sum[j][q-1]);
	}
    return 0;
}
