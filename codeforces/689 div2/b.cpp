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
#define mo 1000000007
typedef long long ll;
using namespace std;
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 505
#define M 505
int n, m, ans;
char s[N][M];
int pre[N][M];
inline int check(int &x, int &y){
	int res=0;
	for (int i=x, k=1;i<=n && (y-k+1>0) && (y+k-1<=m);i++, k++){
		if (pre[i][y+k-1]-pre[i][y-k]<2*k-1) return res;
		res++;
	}
	return res;
}
void solve(){
	ans=0;
	n=read();m=read();
	for (int i=1;i<=n;i++) scanf("%s", s[i]+1);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			pre[i][j]=pre[i][j-1]+(s[i][j]=='*');
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			ans+=check(i,j);
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
