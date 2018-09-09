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
#define lowbit(x) (x&(-x))
#define num(x) (x>='0' && x<='9')
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, q, a[N];
ll c[N], c2[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(int x, int y){
	ll y2=(ll)y*(n-x+1);
	for (int i=x;i<=n;i+=lowbit(i))
		c[i]+=y,
		c2[i]+=y2;
}
ll sum(int x){
	ll p=0;
	for (;x;x-=lowbit(x)) p+=c[x];
	return p;
}
ll sum2(int x){
	ll p=0;
	for (;x;x-=lowbit(x)) p+=c2[x];
	return p;
}
int main(){
	n=read();q=read();
	for (int i=1;i<=n;i++)
		a[i]=read(),
		upd(i,a[i]);
	for (int i=1;i<=q;i++){
		int op=read(), l=read(), r=read();
		if (op==1){
			ll ans=sum2(r)-sum2(l-1);
			ans-=(sum(r)-sum(l-1))*(n-r);
			printf("%lld\n", ans);
		}
		else{
			upd(l,r-a[l]);
			a[l]=r;
		}
	}
    return 0;
}
