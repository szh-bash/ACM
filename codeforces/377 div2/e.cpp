#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c, u, cnt, a[300000], b[300000], p[300000], s[300000], next[9000000], nu[9000000], f[300000], ans1[300000], ans2[300000];
bool cmp1(int x, int y){return a[x]>a[y];}
bool cmp2(int x, int y){return b[x]>b[y];}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)	scanf("%d", &p[i]), a[i]=i;
	for (int i=1;i<=m;i++)  scanf("%d", &s[i]), b[i]=i;
	sort(a+1,a+1+n,cmp1);
	sort(b+1,b+1+m,cmp2);
	int j=1;
	for (int i=1;i<=n;i++){
		cnt=200000;
		while (j<=m && s[b[j]]>=p[a[i]]){
			int x=s[b[j]];
			while (x){
				next[++cnt]=next[x];
				next[x]=cnt;
				nu[cnt]=b[j];
				if (x==1) break;
				x=(x+1)/2;
			}
			j++;
		}
		while (next[p[a[i]]] && f[nu[next[p[a[i]]]]]) next[p[a[i]]]=next[next[p[a[i]]]];
		if (next[p[a[i]]]){
			int w=nu[next[p[a[i]]]];
			f[w]=1;
			ans1[a[i]]=w;
			c++;
			while (s[w]>p[a[i]]) s[w]=(s[w]+1)/2, u++, ans2[w]++;
		}
	}
	cout<<c<<' '<<u<<endl;
	for (int i=1;i<=m;i++) cout<<ans2[i]<<' ';cout<<endl;
	for (int i=1;i<=n;i++) cout<<ans1[i]<<' ';cout<<endl;
	return 0;
}
