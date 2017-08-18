#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, m;
long long ans, l[60000], t[60000][10]; 
int main(){
	scanf("%d%d", &n, &m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%I64d", &t[i][j]);
	for (int i=1;i<=n;i++){
		ans=0;
		for (int j=1;j<=m;j++) ans=max(l[j],ans)+t[i][j], l[j]=ans;
		printf("%I64d", ans);
		if (i!=n) printf(" ");else printf("\n");
	}
	return 0;
}
