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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 200000
int pre[N];
int l[N];
int get(int x, int r){
	int le=0, ri=r;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (pre[mid]>=x) ri=mid;
		else le=mid;
	}
	return ri;
}
void solve(int T){
	int a=read(), b=read(), n=read();
	int ta=a, tb=b;
	for (int i=1;i<=a;i++) l[i]=read();
	int r=0;
	for (int i=1;i<=a && pre[i-1]<a;i++) pre[i]=pre[i-1]+l[i], r=i;
	for (int i=1;i<=n && (i==1 || a!=ta || b!=tb) && (a!=1 || b!=1);i++){
		int t=get(a, r);
		b=a-pre[t-1];
		a=t;
	}
	printf("Case #%d: %d-%d\n", T, a, b);
}
int main(){
	for (int _=read(), o=1;_;_--, o++) solve(o);
    return 0;
}
