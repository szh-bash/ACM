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
#define N 2000000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int a[N], b[N], n;
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
bool check(int x){
	int o=0;
	for (int i=1;i<=n;i++){
		if (a[i]<=x) continue;
		if (!o) {o^=a[i];continue;}
		o^=a[i];
		if (o) return 0;
	}
	if (o) return 0;
	for (int i=1;i<=n;i++){
		if (b[i]<=x) continue;
		if (!o) {o^=b[i];continue;}
		o^=b[i];
		if (o) return 0;
	}
	return 1;
}
int main(){
	n=read();
	int ma=0;
	for (int i=1;i<=n;i++) a[i]=read(), ma=max(ma,a[i]);
	for (int i=1;i<=n;i++) b[i]=read(), ma=max(ma,b[i]);
	int le=-1, ri=ma;
	while (le<ri-1){
		int mid=le+ri>>1;
		if (check(mid)) ri=mid;else le=mid;
	}
	cout<<ri<<endl;
    return 0;
}
