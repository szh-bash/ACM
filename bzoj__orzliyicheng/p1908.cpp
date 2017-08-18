#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, fa[1001], root;
struct zsm{
	int n, c;
	double w;
}l[1001];
int main(){
	freopen("1.in","r",stdin);
	cin>>n>>root;
	while (n && root){
		int ans=0;
		for (int i=1;i<=n;i++) cin>>l[i].c, l[i].n=1, ans+=l[i].c, l[i].w=l[i].c;
		for (int i=1;i<n;i++){
			int x, y;
			cin>>x>>y;
			fa[y]=x;
		}
		for (int i=1;i<n;i++){
			int m, f;double maxx=0;
			for (int j=1;j<=n;j++)
				if (j!=root && l[j].w>maxx) maxx=l[j].w, m=j;
			f=fa[m];
			l[m].w=0;
			ans+=l[f].n*l[m].c;
			for (int j=1;j<=n;j++)
				if (fa[j]==m) fa[j]=f;
			l[f].c+=l[m].c;
			l[f].n+=l[m].n;
			l[f].w=(double)l[f].c/l[f].n;
		}
		cout<<ans<<endl;
		cin>>n>>root;
	}
	return 0;
}
