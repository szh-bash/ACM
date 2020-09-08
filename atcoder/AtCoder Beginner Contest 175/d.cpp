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
#define N 10000
int n, k, p[N], c[N], flag[N];
ll ans, f[N];
int main(){
	ans=-1ll*999999999*999999999;
	n=read();k=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=n;i++)
		if (!flag[i]){
			int ct;
			flag[i]=1;
			f[ct=1]=c[i];
			for (int j=p[i];j && !flag[j];j=p[j], ct++)
				flag[j]=1,
				f[ct+1]=f[ct]+c[j];
			int v=k%ct;
			for (int j=1;j<=ct;j++)
				for (int p=1;p<=min(ct, k);p++)
					ans=max(ans, f[min(j+p,ct)]-f[j]+f[max(0,p-ct+j)]+f[ct]*((k-p)/ct)*(f[ct]>0));
		}
	cout<<ans<<endl;
    return 0;
}
