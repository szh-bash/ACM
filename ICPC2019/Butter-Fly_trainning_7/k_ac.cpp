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
typedef unsigned long long ll;
//typedef long long ll;
using namespace std::tr1;
using namespace std;
#define M 60000000
#define N 3000000
ll n, m, k;
ll tn[M], off[M];
ll rn[N], rff[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll back(int j, ll res){
	while (j--) res=(res+off[j]-1)%tn[j]+1;
	return res;
}
ll get(ll n, ll m, ll k){
	ll x=0;
	int rnt=0;
	while (m){
		rff[rnt]=(k-1)%n+1;
		rn[rnt++]=n;
		--n;
		--m;
	}
	while (rnt--) x=(x+rff[rnt]-1)%rn[rnt]+1;
	return x;
}
ll solve(){
	cin>>n>>m>>k;
	if (k==1) return m;
	if (m<=2000000) return get(n,m,k);
	ll nt=n-m+k;
	ll mt=k;
	ll res=get(nt,mt,k);
	while (mt<m){
		ll ct=min(m-mt,(nt-res)/(k-1)+1);
		nt+=ct;
		mt+=ct;
		res=(res+ct*k-1)%nt+1;
	}
	return res;
}
int main(){
	for (int _=read(), o=1;_;_--, o++)
		printf("Case #%d: %I64d\n", o, solve());
    return 0;
}
