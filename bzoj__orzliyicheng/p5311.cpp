#include<set>
#include<map>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define inf (100000000LL)
#define mp make_pair
#define pli pair<ll,int>
#define pii pair<int,int>
#define ll long long 
#define N 4005
#define sum(j,i) (f[i][i]-f[i][j-1]-f[j-1][i]+f[j-1][j-1])/2
using namespace std;
int n, k;
ll ans;
pli g[N];
int f[N][N];
int pos;
char s[40000000+5];
int read(){
	int x=0;
	while(s[pos] && (s[pos]<'0'|| s[pos]>'9')) pos++;
	while(s[pos] && (s[pos]>='0'&&s[pos]<='9')) x=x*10+s[pos++]-'0';
	return x;
}
int q[N], ti[N];
bool check_sort(int u, int v){
	int le=u, ri=n+1;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (g[u].first+sum(u+1,mid)<g[v].first+sum(v+1,mid) ||
			g[u].first+sum(u+1,mid)==g[v].first+sum(v+1,mid) && g[u].second>=g[v].second) ri=mid;
		else le=mid;
	}
	ti[u]=ri;
	return ti[u]<=ti[v];
}
bool check(int x){
	int ct=1;
	for (int i=1, j=1;i<=n;i++){
		for (j>ct?j=ct:0;j<ct && ti[q[j+1]]<=i;j++);
		g[i].first=g[q[j]].first+sum(q[j]+1,i)-x;
		g[i].second=g[q[j]].second+1;
		while (ct && check_sort(i,q[ct])) ct--;
		q[++ct]=i;
	}
	return g[n].second<k;
}
int main(){
	fread(s,1,35000000,stdin);
	n=read();k=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+read();
	for (int le=-inf, ri=0;le<ri-1;){
		int mid=le+ri>>1;
		if (check(mid)) le=mid;else ri=mid, ans=g[n].first+1ll*mid*k;
	}
	cout<<ans<<endl;
	return 0;
}
