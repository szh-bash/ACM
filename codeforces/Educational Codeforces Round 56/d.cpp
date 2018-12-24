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
#define M (N*3)
#define mo 998244353
typedef long long ll;
using namespace std;
int n, m, cnt, nex[M], nu[M], flag[N], l[N];
int bit[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
ll power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	bit[0]=1;
	for (int i=1;i<N;i++) bit[i]=(bit[i-1]<<1)%mo;
	for (int _=read();_;_--){
		cnt=n=read();m=read();
		for (int i=1;i<=n;i++) nex[i]=flag[i]=0;
		for (int i=1;i<=m;i++){
			int u=read(), v=read();
			add(u,v);
			add(v,u);
		}
		int bf=0;
		ll ans=1;
		for (int i=1;i<=n;i++)
			if (!flag[i]){
				l[1]=i;
				flag[i]=1;
				int le=0, ri=1;
				int odd=0, even=0;
				while (le<ri){
					int u=l[++le];
					if (flag[u]>0) odd++;else even++;
					for (int j=nex[u];j;j=nex[j]){
						int v=nu[j];
						if (flag[v]){
							if (flag[u]!=flag[v]) continue;
							bf=-1;
							break;
						}
						else{
							flag[v]=-flag[u];
							l[++ri]=v;
						}
					}
				}
				if (bf<0) break;
				ans=ans*(bit[odd]+bit[even])%mo;
			}
		if (bf<0) ans=0;
		printf("%I64d\n", ans);
	}
	return 0;
}
