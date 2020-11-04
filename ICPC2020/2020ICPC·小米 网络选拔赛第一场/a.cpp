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
#define N 200005
#define M 10000005
int n, a[N], b[N], ct, ans, f[M];
int main(){
	n=read();
	int le=10000000, ri=0;
	for (int i=1;i<=n;i++)
		a[i]=read(),
		le=min(le,a[i]),
		ri=max(ri,a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i-1]) a[++ct]=a[i], b[ct]=1;
		else b[ct]++;
	n=ct;
	for (int i=n;i;i--){
		int x=a[i], ma=0;
		if (ri/x>n-i){
			for (int j=i+1;j<=n;j++)
				if (a[j]%x==0 && f[a[j]]>ma) ma=f[a[j]];
		}
		else{
			for (int j=1;j*x<=ri;j++)
				if (f[j*x]>ma) ma=f[j*x];
		}
		f[x]=ma+b[i];
		if (f[x]>ans) ans=f[x];
	}
	cout<<ans<<endl;
    return 0;
}
