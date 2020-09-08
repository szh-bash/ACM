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
#define N 3005
int x[N], y[N], num[N], n;
bool cmp(int a, int b){
	if (x[a]<x[b]) return 1;
	if (x[a]>x[b]) return 0;
	return y[a]<y[b];
}
int main(){
	for (int _=read();_;_--){
		n=read()*3;
		for (int i=1;i<=n;i++) x[i]=read(), y[i]=read(), num[i]=i;
		sort(num+1, num+1+n, cmp);
		n/=3;
		for (int i=1;i<=n;i++) printf("%d %d %d\n", num[i*3-2], num[i*3-1], num[i*3]);
	}
    return 0;
}
