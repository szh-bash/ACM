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
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int ans, n, m, p[100], f[5000000], g[5000000], ct, pd[5000000];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		int u=read(), v=read(), w=read();
		p[u]-=w;
		p[v]+=w;
	}
	for (int i=0;i<n;i++)
		if (!p[i]) p[i--]=p[--n];
	int k=1<<n;
	for (int i=1;i<k;i++){
		int w=0;
		for (int j=0;j<n;j++)
			if (i&(1<<j)) w+=p[j];
		if (!w) g[++ct]=i, pd[i]=1;
	}
	for (int i=1;i<k;i++){
		if (!pd[i]) continue;
		for (int j=1;j<=ct && g[j]<=i;j++)
			if (((g[j] & i)^g[j])==0)
				f[i]=max(f[i^g[j]]+1,f[i]);
		ans=max(f[i],ans);
	}
	cout<<n-ans<<endl;
    return 0;
}
