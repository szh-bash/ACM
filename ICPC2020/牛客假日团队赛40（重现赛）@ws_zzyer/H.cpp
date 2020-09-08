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
#define N 60000
int n, d, f[N], q[N];
struct pa{
	int x, h, n;
}l[N];
bool cmp1(pa a, pa b){
	return a.x<b.x;
}
bool cmp2(pa a, pa b){
	return a.x>b.x;
}
void work(){
	int t=0, h=1;
	for (int i=1;i<=n;i++){
		while (t>=h && l[q[t]].h<=l[i].h) t--;
		q[++t]=i;
		while (h<=t && d<abs(l[i].x-l[q[h]].x)) h++;
		f[l[i].n]+=(l[q[h]].h>=2*l[i].h);
	}
}
int main(){
	n=read(), d=read();
	for (int i=1;i<=n;i++) l[i].x=read(), l[i].h=read(), l[i].n=i;
	sort(l+1,l+1+n,cmp1);
	work();
	sort(l+1,l+1+n,cmp2);
	work();
	int ans=0;
	for (int i=1;i<=n;i++) ans+=f[i]==2;
	cout<<ans<<endl;
    return 0;
}
