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
#define N 10000
int n;
ll t[N], p[N];
ll pret[N], prep[N];
ll preti[N], prepi[N];
ll f[N][2];
const ll inf=1ll*999999999*999999999;
ll solve(){
	n=read();
	for (int i=1;i<=n;i++) t[i]=read(), p[i]=read();
	for (int i=1;i<=n;i++)
		pret[i]=pret[i-1]+t[i],
		prep[i]=prep[i-1]+p[i],
		preti[i]=preti[i-1]+t[i]*i,
		prepi[i]=prepi[i-1]+p[i]*i;
	for (int i=1;i<=n;i++){
		f[i][0]=prep[i]*(i+1)-prepi[i];
		f[i][1]=pret[i]*(i+1)-preti[i];
		for (int j=i-1;j;j--){
			int mid=i+j>>1;
			f[i][0]=min(f[i][0], f[j][1]+
								(prepi[mid]-prepi[j])-(prep[mid]-prep[j])*j+
								(prep[i]-prep[mid])*(i+1)-(prepi[i]-prepi[mid]));
			
			f[i][1]=min(f[i][1], f[j][0]+
								(preti[mid]-preti[j])-(pret[mid]-pret[j])*j+
								(pret[i]-pret[mid])*(i+1)-(preti[i]-preti[mid]));
			
		}
	}
	ll ans=inf;
	for (int j=n-1;j;j--)
		ans=min(ans, f[j][0]+preti[n]-preti[j]-(pret[n]-pret[j])*j),
		ans=min(ans, f[j][1]+prepi[n]-prepi[j]-(prep[n]-prep[j])*j);
	return ans;
}
int main(){
	for (int _=read(), O=1;_;_--, O++)
		printf("Case #%d: %I64d\n", O, solve());
    return 0;
}
