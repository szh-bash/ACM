#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int num[70], K;
long long L, R, F[70][4000][2], G[70][700][70][2];
inline long long dfs1(int n, int s, int flag, int t){
	if (!n) return s;
	if (!flag && F[n][s][t]) return F[n][s][t];
	int k=flag?num[n]:K-1;
	long long ans=0;
	for (int i=k;i>=0;i--)
		ans+=dfs1(n-1, s+i*(n-1), flag && (num[n]==i), t);
	if (!flag) F[n][s][t]=ans;
	return ans;
}
inline long long dfs2(int n, int s, int m, int flag, int t){
	if (s<0) return 0;
	if (!n) return s;
	if (!flag && G[n][s][m][t]) return G[n][s][m][t];
	int k=flag?num[n]:K-1;
	long long ans=0;
	for (int i=k;i>=0;i--)
		if (n>=m)
			ans+=dfs2(n-1,s+i,m,flag&&(i==num[n]),t);
		else
			ans+=dfs2(n-1,s-i,m,flag&&(i==num[n]),t);
	if (!flag) G[n][s][m][t]=ans;
	return ans;
}
inline long long work(long long x, int t){
	int cnt=0;
	while (x){
		num[++cnt]=x%K;
		x/=K;
	}
	long long ans=dfs1(cnt,0,1,t);
	for (int i=2;i<=cnt;i++)
		ans-=dfs2(cnt,0,i,1,t);
	return ans;
}
int main(){
	cin>>L>>R>>K;
	cout<<work(R,1)-work(L-1,0)<<endl;
	return 0;
}
