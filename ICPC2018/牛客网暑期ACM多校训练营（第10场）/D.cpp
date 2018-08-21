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
#define N 200005
#define mo 998244353
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
using namespace std::tr1;
struct zkj{
	int w, x, y, t;
}l[N];
int n, m, f[N+6], inv[N+6];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int pwd(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int C(int n, int m){
	return (ll)f[n]*inv[m]%mo*inv[n-m]%mo;
}
void add(int &a, int b){
	if (a+b>=mo) a=a+b-mo;else a=a+b;
}
void sub(int &a, int b){
	if (a-b<0) a=a-b+mo;else a=a-b;
}
int main(){
	f[0]=inv[0]=1;
	for (int i=1;i<=N;i++)
		f[i]=(ll)f[i-1]*i%mo,
		inv[i]=pwd(f[i],mo-2);
	for (int _=read();_;_--){
		n=read();m=read();
		int tot=1, cnt=0;
		for (int i=1;i<=m;i++){
			int op=read();
			if (op==2){
				tot++;
				continue;
			}
			if (op==1)
				l[++cnt].x=read(),
				l[cnt].y=read()+1,
				l[cnt].w=read(),
				l[cnt].t=tot-1;
			if (op==3){
				int x=read()-1, y=read(), ans=0;
				for (int j=1;j<=cnt;j++){
					int dt=tot-l[j].t;
					if (l[j].x<=x) sub(ans,(ll)l[j].w*C(dt+x-l[j].x,dt)%mo);
					if (l[j].x<=y) add(ans,(ll)l[j].w*C(dt+y-l[j].x,dt)%mo);
					if (l[j].y<=x) add(ans,(ll)l[j].w*C(dt+x-l[j].y,dt)%mo);
					if (l[j].y<=y) sub(ans,(ll)l[j].w*C(dt+y-l[j].y,dt)%mo);
				}
				printf("%d\n", ans);
			}
		}
	}
    return 0;
}
/*
1
100000 7
1 1 3 1
2
3 2333 6666
2
3 2333 6666
2
3 2333 6666
*/

