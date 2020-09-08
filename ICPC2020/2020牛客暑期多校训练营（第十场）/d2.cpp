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
int a[10], b[10], pa, pb, suma, sumb;
inline void df(int x){
	b[x]--;
	b[x+2]++;
}
void attack(int x){
	a[x]--;
	a[x+2]++;
	if (b[3]){
		df(3);
		pb++;
		sumb--;
	}
	else if (b[4]){
		df(4);
		sumb--;
	}
	else if (b[1]){
//		if (pa) pa--, a[x]++, a[x+2]--;
		df(1);
	}
	else if (b[2]){
//		if (pa) pa--, a[x]++, a[x+2]--;
		df(2);
	}
	if (a[3]+a[4]) pb=0;
}
void solve(){
	suma=0, sumb=0;
	pa=0, pb=0;
	for (int i=1;i<=4;i++) a[i]=read(), suma+=a[i];
	for (int i=1;i<=4;i++) b[i]=read(), sumb+=b[i];
	while (suma && sumb){
		if (a[3]){
			attack(3);
			if (b[1]) df(1);
			else if (b[2]) df(2);
			else pa++;
			suma--;
		}
		else if (a[1]){
			attack(1);
		}
		else if (a[2]){
			attack(2);
		}
		else if (a[4]){
			attack(4);
			suma--;
		}
	}
	int del=min(pa,pb);
	if (suma) pb=0; else pa-=del, pb-=del;
	if (suma+pa && !sumb) puts("Yes");
	else puts("No");
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
