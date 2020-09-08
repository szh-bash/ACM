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
#define N 50000
int n, v[4], ct;
ll ans, sum;
struct pa{
	int n, x;
}l[N];
bool cmp(pa a, pa b){
	return a.x<b.x;
}
int main(){
	n=read();
	for (int i=1;i<=3;i++) v[i]=read();
	for (int i=1;i<=n;i++){
		l[++ct].n=i;
		l[ct].x=read();
		l[++ct].n=-i;
		l[ct].x=read()+1;
	}
	sort(l+1,l+1+ct,cmp);
	for (int i=1;i<=n;i++) sum+=v[1];
	ans=sum;
	for (int i=1;i<=ct;i++){
		if (l[i].n<0) sum+=-v[2]+v[3]; else sum+=-v[1]+v[2];
		while (i<ct && l[i+1].x==l[i].x)
			if (l[++i].n<0) sum+=-v[2]+v[3]; else sum+=-v[1]+v[2];
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
    return 0;
}
