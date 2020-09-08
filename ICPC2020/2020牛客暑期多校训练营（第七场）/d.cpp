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
void solve(){
	int n=read();
	if (n==1 || n==24) puts("Fake news!");
	else puts("Nobody knows it better than me!"); 
}
int main(){
//	ll x=0;
//	for (int i=1;i<=1000000;i++){
//		x+=i*i;
//		ll y=sqrt(x);
//		if (y*y==x) cout<<i<<endl;
//	}
//	return 0;
	for (int _=read();_;_--) solve();
    return 0;
}
