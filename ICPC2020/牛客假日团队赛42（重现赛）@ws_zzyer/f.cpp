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
struct pt{
	int n, x, y;
}
bool cmp(pt a, pt b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.y<b.y;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		l[++ct].n=i;
		l[ct].x=read(), l[ct].y=read();
		sx[i]=l[ct].x;
		sy[i]=l[ct].y;
		l[++ct].n=-i;
		l[ct].x=read(), l[ct].y=read();
		tx[i]=l[ct].x;
		ty[i]=l[ct].y;
	}
	sort(l+1,l+1+ct,cmp);
	int x=0, y=0, t=1;
	for (int i=2;i<=ct;i++){
		if (l[i].x==x) continue;
		
	}
    return 0;
}
