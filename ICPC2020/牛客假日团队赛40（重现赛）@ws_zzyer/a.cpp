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
#define N 200000
int n, m, Q, p[N];
int fa[N][32];
int power[32];
int main(){
	n=read();m=read();Q=read();
	for (int i=1;i<=m;i++) p[i]=read(), fa[p[i]][0]=i+1>m?0:i+1;
	for (int j=1;j<=30;j++)
		for (int i=1;i<=m;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	power[0]=1;
	for (int i=1;i<=30;i++) power[i]=power[i-1]<<1;
	for (int i=1;i<=Q;i++){
		int q=read();
		int v=max(1,m-q+1), k=n-max(q,m)+1, sum=q<m?0:(n-m+1-k), pos;
		for (int j=30;j>=0;j--)
			if (fa[v][j] && k>=power[j]) v=fa[v][j], k-=power[j], sum+=power[j];
		if (k) pos=n-sum;else pos=n-sum-m+v;
		printf("%d\n", pos);
	}
    return 0;
}
