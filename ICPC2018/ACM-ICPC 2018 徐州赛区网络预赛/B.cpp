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
#define GE "Good Ending"
#define BE "Bad Ending"
#define NE "Normal Ending"
#define N 5000
#define M 200
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, m, k, l, f[3][M+5], a[N], b[N], c[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	cin>>n>>m>>k>>l;
	l+=100;
	k+=100;
	m+=100;
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=read(), c[i]=read();
	for (int i=0, o=1^(n&1);i<=M;i++)
		if (i>=k) f[o][i]=1;
		else if (i<=l) f[o][i]=-1;
		else f[o][i]=0;
	for (int i=n, o=n&1;i;i--, o^=1)
		for (int j=0;j<=M;j++){
			f[o][j]=o?-1:1;
			if (a[i])
				if (o) f[o][j]=max(f[o][j],f[o^1][min(j+a[i],M)]);
				else f[o][j]=min(f[o][j],f[o^1][min(j+a[i],M)]);
			if (b[i])
				if (o) f[o][j]=max(f[o][j],f[o^1][max(j-b[i],0)]);
				else f[o][j]=min(f[o][j],f[o^1][max(j-b[i],0)]);
			if (c[i])
				if (o) f[o][j]=max(f[o][j],f[o^1][M-j]);
				else f[o][j]=min(f[o][j],f[o^1][M-j]);
		}
	if (f[1][m]==1) cout<<GE<<endl;
	if (!f[1][m]) cout<<NE<<endl;
	if (f[1][m]==-1) cout<<BE<<endl;
    return 0;
}
