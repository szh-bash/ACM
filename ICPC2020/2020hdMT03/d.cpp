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
#define N 100005
int n, p, f[N], ex[N];
void solve(){
	n=read();p=read();
	ex[0]=0;
	for (int i=1;i<p;i++) ex[i]=-1;
	int sum=0;
	for (int i=1;i<=n;i++){
		int x=read()%p;
		f[i]=f[i-1]+(!x);
		sum=(sum+x)%p;
		if (ex[sum]>=0) f[i]=max(f[i], f[ex[sum]]+1);
		ex[sum]=i;
	}
	cout<<f[n]<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
