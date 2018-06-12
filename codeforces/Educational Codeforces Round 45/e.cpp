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
#define N 2000000
typedef long long ll;
using namespace std;
const ll INF = (ll) 1000000000*1000000;
int n, m, k, f[N], a[N], g[N];
ll ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	ans=INF;
	n=read();m=read();k=read();
	for (int i=1;i<=m;i++) f[read()]=1;
	for (int i=1;i<=k;i++) a[i]=read();
	g[0]=f[0]?-1:0;
	for (int i=1;i<=n;i++)
		g[i]=f[i-1]?g[i-1]:i-1;
	for (int i=1;i<=k;i++){
		int flag=0;
		ll sum=0;
		for (int j=0;j<n;j+=i)
			if (f[j]){
				if (j==0 || g[j]+i<=j){
					flag=1;
					break;
				}
				else
					j=g[j],
					sum+=a[i];
			}
			else sum+=a[i];
		if (flag) continue;
		if (sum<ans) ans=sum;
	}
	if (ans==INF) ans=-1;
	cout<<ans<<endl;
	return 0;
}
