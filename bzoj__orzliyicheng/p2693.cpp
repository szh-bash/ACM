#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define MAX 10000000
#define mo 100000009
using namespace std;
int t, cnt, zs[1000000], f[10000000];
int g[10000000];
int main(){
	f[1]=g[1]=1;
	for (int i=2;i<=MAX;i++){
		if (!f[i]) zs[++cnt]=i, g[i]=1-i;	
		for (int j=1;j<=cnt && i*zs[j]<=MAX;j++){
			f[i*zs[j]]=1;
			if (i%zs[j]==0) {g[i*zs[j]]=g[i];break;}
			else g[i*zs[j]]=g[i]*(1-zs[j])%mo;
		}
	}
	for (int i=1;i<=MAX;i++) g[i]=(g[i-1]+(long long)g[i]*i)%mo;
	scanf("%d", &t);
	for (int i=1;i<=t;i++){
		int ans=0, n, m, p;
		scanf("%d%d", &n, &m);
		if (n>m) swap(n, m);
		for (int k=1;k<=n;k=p+1){
			p=min(n/(n/k),m/(m/k));
			ans+=(((long long)(n/k)*(n/k+1)/2%mo)*((long long)(m/k)*(m/k+1)/2%mo)%mo)*(g[p]-g[k-1])%mo;
			ans%=mo;
		}
		if (ans<0) ans+=mo;
		printf("%d\n", ans);
	}
	return 0;
}
