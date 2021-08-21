#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define N 3006
#define M 3006
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
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
ll s[N][M], f[N];
int add(int a, int b){
	if (a+b>=mo) return a+b-mo;
	return a+b;
}
void solve(int n, int m){
	int ans=0;
	for (int i=1;i<=n;i++){
		if (i-1 && i-1<=m)
			ans=add(ans,s[n][i]*s[m][i-1]%mo);
		if (i<=m)
			ans=add(ans,s[n][i]*s[m][i]*2%mo);
		if (i+1<=m)
			ans=add(ans,s[n][i]*s[m][i+1]%mo);
	}
	printf("%d\n", ans);
}
int main(){
	s[0][0]=1;
	for (int i=1;i<N;i++)
		for (int j=1;j<M;j++)
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*j)%mo;
	
	f[0]=1;
	for (int i=1;i<N;i++) f[i]=f[i-1]*i%mo;
	for (int i=1;i<N;i++)
		for (int j=1;j<M;j++)
			s[i][j]=s[i][j]*f[j]%mo;
	for (int _=read();_;_--){
		int n=read(), m=read();
		solve(n,m);
	}
    return 0;
}
