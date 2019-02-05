#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 500000
typedef long long ll;
using namespace std;
int n, m;
ll a[N], c[N], num[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(int x, int y){
	if (c[x]<c[y]) return 1;
	if (c[x]>c[y]) return 0;
	return (x<y);
}
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=n;i++) num[i]=i;
	sort(num+1,num+1+n,cmp);
	int j=1;
	for (int i=1;i<=m;i++){
		ll ans=0;
		ll t=read(), d=read();
		ll eat=min((ll)a[t],d);
		ans+=eat*c[t];
		a[t]-=eat;
		d-=eat;
		if (d){
			while (j<=n && d){
				eat=min((ll)a[num[j]],d);
				ans+=eat*c[num[j]];
				a[num[j]]-=eat;
				d-=eat;
				if (!a[num[j]]) j++;
			}
		}
		if (d) ans=0;
		printf("%I64d\n", ans);
	}
	return 0;
}
