#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	cin>>T;
	while (T--){
		int u, v;
		cin>>n>>m;
		memset(f,0,sizeof(f));
		for (int i=1;i<=m;i++){
			scanf("%d%d", &u, &v);
			f[u]++;f[v]++;
			a[u][v]=a[v][u]=1;
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (i!=j && f[i]==f[j] && f[i]>tmp){
					tmp=f[i];
					s=i;
					t=j;
				}
		int le=0, ri=1;
		memset(flag,0,sizeof(flag));
		l[1]=s;
		flag[s]=1;
		while (le<ri){
			u=l[le];
			for (int i=1;i<=n;i++)
				if (a[u][i] && flag[i]){
					l[++ri]=i;
					b[u][i]=1;
				}
		}
		dfs(s);
		cout<<
		for (int i=1;i<=n;i++)
	}
	return 0;
}
