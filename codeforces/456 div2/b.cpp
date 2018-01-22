#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
long long n, k, i, ans, m, w[100], f[100];
int main(){
	cin>>n>>k;
	for (i=1, m=0; i<=n; i<<=1, m++);
	m--;
	i>>=1;
	f[0]=1;
	for (int j=1;j<=m;j++) f[j]=f[j-1]<<1;
	for (int j=1;j<=k;j++){
		long long v=0;
		for (int q=m;q>=0;q--)
			if (!w[q] && v+f[q]<=n) v+=f[q], w[q]=1;
		ans+=v;
		if (!v) break;
	}
	cout<<ans<<endl;
	return 0;
}
