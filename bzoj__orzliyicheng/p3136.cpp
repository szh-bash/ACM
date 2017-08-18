#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define MAXN 10000001
using namespace std;
int m, q, x, n, cnt, f[MAXN], dis[MAXN];
int main(){
	scanf("%d%d", &m, &q);
	for (int i=1;i<=m;i++){
		scanf("%d", &x);
		if (!f[x])
			for (int j=0;j<=MAXN/x;j++) f[j*x]=max(f[j*x],x);
	}
	int k=0, r=0, top=0;
	for (int j=0;j<=MAXN;j++)
		if (j<=k) r=max(r, j+f[j]-1),dis[j]=top;
		else{
			if (k==r) break;
			k=r;
			j--;
			top++;
		}
	for (int i=1;i<=q;i++){
		scanf("%d", &n);
		if (dis[n]) printf("%d\n",dis[n]);else printf("oo\n");
	}
	return 0;
}
