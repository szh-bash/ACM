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
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, g[24], a[24], b[24], s[24];
ll f[1<<21];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	g[0]=1;
	n=read();
	for (int i=1;i<=n;i++) g[i]=g[i-1]<<1;
	for (int i=0;i<n;i++){
		a[i]=read();b[i]=read();
		for (int j=read();j;j--) s[i]|=g[read()-1];
	}
	int T=g[n];
	memset(f,-1,sizeof(f));
	f[0]=0;
	for (int i=0;i<T;i++){
		if (f[i]<0) continue;
		int tot=1;
		for (int j=0;j<n;j++)
			if (i&(1<<j)) tot++;
		for (int j=0;j<n;j++)
			if (!(i&(1<<j)) && ((i&s[j])==s[j]))
				f[i|(1<<j)]=max(f[i|(1<<j)],f[i]+(ll)tot*a[j]+b[j]);
	}
	cout<<f[T-1]<<endl;
    return 0;
}
