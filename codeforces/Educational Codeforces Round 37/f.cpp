#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#define M 1000010
#define N 2000000
typedef long long ll;
using namespace std;
int n, m, a[N], pre[N], nex[N], f[N];
ll c[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int get_pre(int x){ return pre[x]==x?x:pre[x]=get_pre(pre[x]);};
int get_nex(int x){ return nex[x]==x?x:nex[x]=get_nex(nex[x]);};
void unio(int u, int v){
	pre[get_pre(v)]=get_pre(u);
	nex[get_nex(u)]=get_nex(v);
}
void update(int x, int y){
	for (int i=x;i<=n;i+=i&(-i)) c[i]+=y;
}
ll sum(int x){
	ll p=0;
	for (int i=x;i;i-=i&(-i)) p+=c[i];
	return p;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=M;i++)
		for (int j=1;j<=M/i;j++)
			f[i*j]++;
	a[0]=a[n+1]=100;
	for (int i=1;i<=n;i++) a[i]=read(), pre[i]=nex[i]=i;
	for (int i=1;i<=n;i++){
		update(i,a[i]);
		if (a[i]<=2){
			if (a[i-1]<=2) unio(i-1,i);
			if (a[i+1]<=2) unio(i,i+1);
		}
	}
	for (int i=1;i<=m;i++){
		int t=read(), l=read(), r=read();
		if (t==2){
			printf("%I64d\n", sum(r)-sum(l-1));
		}
		else{
			for (int j=l;j<=r;j=get_nex(j)+1)
				if (a[j]>2){
					update(j,-a[j]);
					update(j,f[a[j]]);
					if (f[a[j]]<=2){
						if (a[j-1]<=2) unio(j-1,j);
						if (a[j+1]<=2) unio(j,j+1);
					}
					a[j]=f[a[j]];
				}
		}
	}
	return 0;
}
