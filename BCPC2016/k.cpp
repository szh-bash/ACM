#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long f[3000000], g[3000000], p[3000000];
int n, sum, d[30];
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>n;
		sum=0;
		for (int i=1;i<=n;i++) scanf("%d", &d[i]), sum+=d[i];
		long long ans=0;
		for (int i=1;i<=sum;i++)
			f[i]=i<=d[1],g[i]=g[i-1]+f[i];
		for (int i=2;i<=n;i++){
			for (int j=1;j<=sum;j++)
				f[j]=p[j]=0;
			for (int j=i;j<=sum;j++){
				int k=min(d[i],j-i+1);
				f[j]=g[j-1]-g[j-k-1];
				p[j]=p[j-1]+f[j];
			}
			for (int j=1;j<=sum;j++)
				g[j]=p[j];
		}
		for (int i=n;i<=sum;i++)
			ans=max(f[i], ans);
		cout<<ans<<endl;
	}
	return 0;
}
