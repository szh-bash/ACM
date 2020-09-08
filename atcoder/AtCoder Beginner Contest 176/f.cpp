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
#define N 2005
int n, a[N*3], f[N], ans;
void solve(int x){
	sort(a+x,a+x+6);
	for (int j=0;j<3;j++)
		if (a[x+j]==a[x+j+1] && a[x+j+1]==a[x+j+2]){
			a[x+j]=a[x+j+1]=a[x+j+2]=0;
			sort(a+x,a+x+6);
			ans++;
			return;
		}
	for (int j=1;j<=3;j++){
		int ma=-1, p;
		for (int k=0;k<5;k++)
			if (a[x+k] && (f[a[x+k]]<3?999:0)+f[a[x+k]]%3>ma) ma=(f[a[x+k]]<3?999:0)+f[a[x+k]]%3, p=k;
		f[a[x+p]]--;
		a[x+p]=0;
	}
	sort(a+x,a+x+6);
}
int main(){
	n=read();
	for (int i=1;i<=n*3;i++) a[i]=read(), f[a[i]]++;
	for (int i=1;i<=(n-1)*3;i+=3) solve(i);
	ans+=(a[n]==a[n-1] && a[n-1]==a[n-2]);
	cout<<ans<<endl;
    return 0;
}
