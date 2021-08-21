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
int get(int x){
	for (int i=2;i*i<=x;i++)
		if (x%i==0) return i;
	return x<2?0:x;
}
void solve(int a, int b){
	// int a=read(), b=read();
	if (a>b) swap(a,b);
	// for (int i=2;i<=b;i++)
	// 	if (a%i==b%i) printf("%d ", i);
	// puts("");
	int ans=0;
	if (b-a==0){
		if (a>1) printf("%d %d\n", 2, a);
		else puts("-1 -1");
		return;
	}
	else if (b-a==1){
		puts("-1 -1");
		return;
	}
	ans=get(b-a);
	printf("%d %d\n", ans, b-a);
}
int main(){
	// srand(unsigned(time(NULL)));
	for (int _=read();_;_--){
		// int x=rand(), y=rand();
		// cout<<x<<' '<<x<<endl;
		solve(read(),read());
	}
    return 0;
}
