#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 500000
typedef long long ll;
using namespace std;
int n, top, st[N];
int d[N], num[N], fa[N], f[N];
int flag[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int cmp(int a, int b){return d[a]<d[b];}
int father(int x){return fa[x]==x?x:fa[x]=father(fa[x]);}
vector <int> g[N];
int main(){
	n=read();
	for (int i=1;i<=n;i++) d[i]=read(), num[i]=i;
	sort(num+1, num+1+n, cmp);
	for (int i=1;i<=2*n;i++) fa[i]=i, f[i]=1;
	for (int i=1;i<=n;i++)
		if (d[num[i-1]]==d[num[i]] && f[father(num[i-1])]+1<=d[num[i-1]])
			fa[num[i]]=fa[num[i-1]],
			f[fa[num[i-1]]]++,
			g[fa[num[i-1]]].push_back(num[i]);
		else g[num[i]].push_back(num[i]);
	for (int i=1;i<=n;i++)
		if (!flag[father(i)]){
			st[++top]=father(i);
			flag[fa[i]]=1;
//			cout<<top<<' '<<fa[i]<<endl;
		}
//	cout<<top<<endl;
	for (int i=1;i<=n;i++){
		if (father(i)!=i) continue;
		if (f[father(i)]==d[father(i)]){
			for (int j=0;j<d[i]-1;j++)
				printf("%d %d\n%d %d\n", g[i][j]*2-1, g[i][j+1]*2-1, g[i][j]*2, g[i][j+1]*2);
			printf("%d %d\n", g[i][d[i]-1]*2-1, g[i][0]*2);
		}
		else{
			int j=top, k=1;
			for (;j, k+f[father(i)]<=d[father(i)];j--, k++){
				if (st[j]==father(i)){
					k--;
					continue;
				}
				g[i].push_back(st[j]);
			}
			if (top-j+f[father(i)]>d[i]) st[j+1]=father(i), top=j+1;
			else top=j;
			for (j=0;j+1+k<d[i];j++)
				printf("%d %d\n%d %d\n", g[i][j]*2-1, g[i][j+1]*2-1, g[i][j]*2, g[i][j+1]*2);
			for (;j+1<d[i];j++)
				printf("%d %d\n", g[i][j]*2-1, g[i][j+1]*2-1);
			printf("%d %d\n", g[i][d[i]-1]*2-1, g[i][0]*2);
		}
	}
	for (int i=1;i<top;i++)
		printf("%d %d\n", g[st[i]][0]*2-1, g[st[i+1]][0]*2-1);
	return 0;
}
