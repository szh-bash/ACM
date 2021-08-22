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
ll n, m, k, a[5];
ll calc(int up){
	ll res=0;
	res=((a[3]-a[1]+1+up-1)/k+1)*(2-(a[4]==m)-(a[2]==1));
	res+=((a[4]-a[2]+1-1)/k+1)*(2-(a[1]==1)-(a[3]==n));
	res+=((a[3]-a[1]+1-1)/k+1)*(a[4]-a[2]);
	res+=(a[4]-a[2]+1)*(a[3]-a[1]);
	return res;
}
void solve(int o){
	n=read(), m=read(), k=read();
	for (int i=1;i<=4;i++) a[i]=read();
	ll ans=0;
	if (k==1){
		int up = min(a[1]-1, n-a[3]);
		int left = min(a[2]-1, m-a[4]);
		ans=min(up,left)+(a[3]-a[1]+1)*(a[4]-a[2]+2)+(a[4]-a[2]+1)*(a[3]-a[1]+2);
		// cout<<ans<<endl;
		if (a[1]==1) ans-=a[4]-a[2]+1;
		if (a[3]==n) ans-=a[4]-a[2]+1;
		if (a[2]==1) ans-=a[3]-a[1]+1;
		if (a[4]==m) ans-=a[3]-a[1]+1;
	}
	else{
		ans=1ll*999999999*999999999;
		int up = min(a[1]-1, n-a[3]);
		int left = min(a[2]-1, m-a[4]);
		ans=min(ans,calc(up));
		swap(a[1],a[2]);
		swap(a[3],a[4]);
		swap(n,m);
		ans=min(ans,calc(left));
	}
	printf("Case #%d: ", o);cout<<ans<<endl;
}
int main(){
	for (int _=read(), o=1;_;_--,o++) solve(o);
    return 0;
}
