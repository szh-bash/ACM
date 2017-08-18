#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
long long sum, ans[1000100];
int n, m, f[1000100], flag[1000100], k, b[1000100];
int main(){
	scanf("%d", &m);int x, maxn=0;
	for (int i=1;i<=m;i++) scanf("%d", &x), f[x]=1, maxn=max(maxn,x);
	scanf("%d", &n);
	for (int i=1;i<=n;i++){
		scanf("%d", &x);
		sum=sum+x;
		int tot=x;
		if (!b[x]) b[x]=x;
		for (int j=b[x];j<=maxn && tot;j+=x)
		if (!flag[j]){
			flag[j]=1;
			tot--;
			if (f[j]) ans[++k]=sum-tot;
			b[x]=j+x;
		}
		if (k==m) break;
	}
	cout<<k<<endl;
	for (int i=1;i<=k;i++) printf("%lld\n", ans[i]);
	return 0;
}
