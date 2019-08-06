s#include <map>
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
int n, l[N], r[N];
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
int main(){
	n=read();
	for (int i=1;i<=n;i++) 
		l[i]=read(),
		r[i]=read(),
		w[i]=(double)1/(r[i]-l[i]);
	int T=1<<n;
	for (int i=0;i<n;i++){
		int o=1;
		for (int j=1;j<=i;j<<=1, o++)
			bit[o]=i&j;
		for (;o<=n;o++)
			bit[o]=0;
		for (int j=1;j<=n;j++)
			if (bit[j]) swap(l[j], r[j]), l[j]=-l[j], r[j]=-r[j];
		int cnt=1;
		q[1].l=-inf, q[1].r=inf, q[1].f=1;
		for (int j=1;j<=n;j++){
			int lr=cnt;
			for (int k=1;k<=cnt;k++)
				if (q[k].l>=l[j] && q[k].r<=r[j]) q[k].f*=w[j];
				else
					if (q[k].l<l[j] && l[j]<q[k].r) 
						q[++lr].x=q[k].f*w[j]
					else if (q[k].l<r[j] && r[j]<q[k].r)
		}
		for (int j=1;j<=n;j++)
			if (bit[j]) swap(l[j], r[j]), l[j]=-l[j], r[j]=-r[j];
	}
    return 0;
}
