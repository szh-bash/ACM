#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int flag, w ,v1, v2, x[400], y[400], p, p2, n, m, ans;
int main(){
	cin>>w>>v1>>v2;
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d%d", &x[i], &y[i]);
	cin>>m;
	ans=-1;
	for (int i=1;i<=m;i++){
		int u, v, ww, kk;
		cin>>u>>v>>ww;
		if (u==1) kk=v1;else kk=v2;
			if (v<=w && kk+ww>ans){
				p=i;flag=1;
				ans=kk+ww;
			}
		if (u==1) continue;
		for (int j=1;j<=n;j++)
			if (x[j]*2>=v && w*2>=v && ww+y[j]>ans){
				ans=ww+y[j];
				p=i;flag=2;
				p2=j;
			}
	}
	if (!flag) printf("Forget about apartments. Live in the dormitory.\n");
	else
	if (flag==1) printf("You should rent the apartment #%d alone.\n",p);
	else 
		printf("You should rent the apartment #%d with the friend #%d.\n",p,p2);
	return 0;
}
