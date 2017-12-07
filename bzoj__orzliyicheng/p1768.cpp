#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, p[2000], ans, f[2][1501];
int main(){
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++){
		char s[2000];
			scanf("%s", s);
		for (int j=1;j<=m;j++){
			if (s[j-1]=='1') f[i%2][j]=f[(i+1)%2][j]+1;
				else f[i%2][j]=0;
			p[j]=f[i%2][j];
		}
		sort(p+1,p+1+m);
		for (int j=m;j;j--)
			ans=max(ans,p[j]*(m-j+1));
	}
	cout<<ans<<endl;
	return 0;
}
