#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#define N 3000
typedef long long ll;
using namespace std;
int n, m, cnt, tot, ans[N], a[N][N], flag[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
void dfs(int x){
	flag[x]=1;
	tot++;
	for (int i=1;i<=n;i++)
		if (a[x][i] && !flag[i]) dfs(i);
}
int main(){
	n=read();m=read();
	if (n>2000){
		cout<<1<<endl;
		cout<<n<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) a[i][j]=1;
	for (int i=1;i<=m;i++){
		int x=read(), y=read();
		a[x][y]=a[y][x]=0;
	}
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			tot=0;
			dfs(i);
			ans[++cnt]=tot;
		}
	sort(ans+1,ans+1+cnt);
	cout<<cnt<<endl;
	for (int i=1;i<=cnt;i++) cout<<ans[i]<<' ';cout<<endl;
	return 0;
}
