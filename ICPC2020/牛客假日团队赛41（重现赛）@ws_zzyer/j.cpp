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
#define N 300000
int n, m, f[N], l[N], p[N], g[N], h=1, t;
int main(){
	n=read(), m=read();
	for (int i=1;i<=n+1;i++) p[i]=i;
	for (int i=1;i<=m;i++){
		int a=read(), b=read();
		g[b+1]=max(g[b+1],a);
		p[b]=min(p[b],a);
	}
	for (int i=1;i<=n+1;i++) g[i]=max(g[i-1],g[i]);
	for (int i=n;i;i--) p[i]=min(p[i],p[i+1]);
	for (int i=1, j=1;i<=n+1;i++)
		if (g[i]>=p[i]) f[i]=-999999;
		else {
			while (j<p[i]){
				while (t>=h && j<=n && f[l[t]]<=f[j]) t--;
				l[++t]=j++; 
			}
			while (h<=t && l[h]<g[i]) h++;
			f[i]=f[l[h]]+1;
		}
	if (--f[n+1]<0) f[n+1]=-1;
	cout<<f[n+1]<<endl;
    return 0;
}
