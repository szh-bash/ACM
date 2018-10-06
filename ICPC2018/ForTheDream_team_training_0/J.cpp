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
#define N 1000000
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
const ll INF=(ll) 1000000000*100000;
int n, m, k;
ll x[N][10];
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
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		for (int i=1;i<=n;i++){
			//x[i][0]=read();
			int ss=read();
			x[2*i][0]=ss;
			x[2*i-1][0]=-ss;
			for (int j=1;j<=k;j++)
				x[2*i][j]=x[2*i-1][j]=read();
		}
		n<<=1;
		for (int i=1;i<=m;i++){
			int ss=read();
			x[n+2*i][0]=ss;
			x[n+2*i-1][0]=-ss;
			for (int j=1;j<=k;j++)
				x[n+2*i][j]=x[n+2*i-1][j]=read();
		}
		m<<=1;
		int T=1<<k;
		ll ans=0;
		for (int v=0;v<T;v++){
			ll ma0=-INF, mi0=INF;
			for (int i=1;i<=n;i++){
				ll y=x[i][0];
				for (int j=1, o=1;j<=k;j++, o<<=1)
					if (v&o) y-=x[i][j];
					else y+=x[i][j];
				ma0=max(ma0,y);
				mi0=min(mi0,y);
			}
			ll ma1=-INF, mi1=INF;
			for (int i=n+1;i<=n+m;i++){
				ll y=x[i][0];
				for (int j=1, o=1;j<=k;j++, o<<=1)
					if (v&o) y-=x[i][j];
					else y+=x[i][j];
				ma1=max(ma1,y);
				mi1=min(mi1,y);
			}
			ans=max(ans,max(ma0-mi1,ma1-mi0));
		}
		cout<<ans<<endl;
	}
    return 0;
}
