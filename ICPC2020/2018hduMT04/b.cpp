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
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define mo 1000000007
int pw(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 100005
int power[N], n, m, f[400][N], block, inv[N];
void solve(){
	n=read(), m=read();
	int i=n/block, ed=i*block, bit=1;
	int res=0;
	for (int j=n;j>ed && m;j--)
		res=(res+1ll*power[j-1]*inv[m]%mo*inv[j-1-m]%mo*bit)%mo,
		bit=bit*2%mo,
		m--;
	res=(res+1ll*bit*f[i][m])%mo;
	printf("%d\n", res);
}
int main(){
	block=sqrt(100005);
	f[0][0]=power[0]=1;
	for (int i=1;i<N;i++) power[i]=1ll*power[i-1]*i%mo;
	inv[N-1]=pw(power[N-1],mo-2);
	for (int i=N-2;i>=0;i--) inv[i]=1ll*inv[i+1]*(i+1)%mo; 
	for (int i=1;i*block<N;i++){
		int m=i*block;
		int sum=0;
		for (int j=0;j<=m;j++){
			sum=(sum+1ll*power[m]*inv[j]%mo*inv[m-j])%mo;
			f[i][j]=sum;
		}
	}
	for (int _=read();_;_--) solve();
    return 0;
}
