#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 1999999999
using namespace std;
int n, m, p, t, tp, tmp, ans, a[3000], f[3000], flag[3000], pop;
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	t=n/m;
	for (int i=1;i<=n;i++)
		if (a[i]<=m) f[a[i]]++;
	for (int i=1;i<=m;i++)
		if (f[i]>=t) pop++;
	if (pop<m)
	for (int i=1;i<=n;i++){
		if ((a[i]>m) ||  f[a[i]]>t){
			int j;
			tmp=-1;
			for (j=1;j<=m;j++)
				if (f[j]<t && f[j]>tmp) tmp=f[j], tp=j;
			j=tp;	
					if (a[i]<=m) f[a[i]]--;
					f[j]++;
					a[i]=j;
					ans++;
					if (f[j]==t) pop++;
		}
		if (pop==m) break;
	}
	cout<<t<<' '<<ans<<endl;
	for (int i=1;i<=n;i++) cout<<a[i]<<' ';cout<<endl;
	return 0;
}
