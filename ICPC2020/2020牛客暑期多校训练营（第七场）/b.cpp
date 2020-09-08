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
#define N 50000000
int a[N];
int n, m, ct;
void work(int n, int m){
	if (!m) return;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n/m;j++) a[++ct]=m;
	work(m, n%m);
}
void solve(){
	n=read(), m=read();
	ct=0;
	work(max(n,m), min(n,m)); 
	printf("%d\n", ct);
	for (int i=1;i<=ct;i++) printf("%d%s", a[i], (i==ct?"\n":" "));
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
