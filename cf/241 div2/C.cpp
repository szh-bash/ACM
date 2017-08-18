#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, ans[2000], c[2000], p[2000], nu[2000], n2[2000], r[2000], f[2000], tot, t2;
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d%d", &c[i], &p[i]), nu[i]=i;
	scanf("%d", &m);
	for (int i=1;i<=m;i++) scanf("%d", &r[i]),n2[i]=i;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			if (c[j]<c[i]) swap(c[i],c[j]), swap(p[i],p[j]), swap(nu[i],nu[j]);
	for (int i=1;i<=m;i++)
		for (int j=i+1;j<=m;j++)
			if (r[i]>r[j]) swap(r[i],r[j]), swap(n2[i],n2[j]);
	for (int i=1;i<=m;i++){
		int MAX=0, P=0;
		for (int j=1;j<=n;j++){
			if (c[j]>r[i]) break;
			if (!f[j] && MAX<p[j]) MAX=p[j], P=j;
		}
		if (P){
			f[P]=1;
			ans[nu[P]]=n2[i];
			tot++;
			t2+=MAX;
		}
	}
	cout<<tot<<' '<<t2<<endl;
	for (int i=1;i<=n;i++)
		if (ans[i]) printf("%d %d\n", i, ans[i]);
	return 0;
}
