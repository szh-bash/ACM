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
#define N 1000005
int n, f[N], g[N];
int main(){
	n=read();
	int k=read(), ans=0;
	for (int i=1;i<=k;i++){
		int x=read(), sum=0;
		for (int j=1;j*x<=n;j++)
			g[j*x]^=1;
		for (int j=1;j<=n;j++)
			if (g[j]) sum++;
		ans=max(ans, sum);
	}
	cout<<ans<<endl;
    return 0;
}
