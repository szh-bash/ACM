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
#define M 200000
#define N 1500000
#define S 400000*20*5
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, x, a[N], wv[N], sa[N], rk[N], y[N], r[N];
int fr[M], k[M], f[N+M*3];
char s[S+10];
priority_queue<int, vector<int>, greater<int> > q; 
int read(){
	int p=0;
	while (s[x]!='\0' && (s[x]<'0' || s[x]>'9')) x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
int main(){
//	freopen("M.in","r",stdin);
	fread(s,1,S,stdin);
	while (n=read()){
		int ls=0, sum=0;
		a[ls++]=301;
		for (int i=1;i<=n;++i){
			fr[i]=ls;
			k[i]=read();
			for (int j=1;j<=k[i];j++) a[ls++]=read();
			a[ls++]=301;
			sum+=k[i];
		}
	/*	for (int i=0;(i<<1)<ls;++i)
			swap(a[i],a[ls-i-1]);
		for (int i=1;i<=n;++i)
			fr[i]=ls-1-fr[i];*/
		int m=max(ls,302);
		for (int i=0;i<2*ls;++i) rk[i]=-1;
		for (int i=0;i<m;++i) wv[i]=0; 
		for (int i=0;i<ls;++i) wv[a[i]]++;
		for (int i=1;i<m;++i) wv[i]+=wv[i-1];
		for (int i=0;i<ls;++i) sa[--wv[a[i]]]=i;
		rk[sa[0]]=0;
		for (int i=1;i<ls;++i) rk[sa[i]]=rk[sa[i-1]]+(a[sa[i]]!=a[sa[i-1]]);
		for (int j=1;j<ls;j*=2){
			int p=0;
			for (int i=ls-j;i<ls;++i) y[++p]=i;
			for (int i=0;i<ls;++i)
				if (sa[i]>=j) y[++p]=sa[i]-j;
			for (int i=0;i<m;++i)  wv[i]=0;
			for (int i=0;i<ls;++i) wv[rk[i]]++;
			for (int i=1;i<m;++i) wv[i]+=wv[i-1];
			for (int i=ls;i;--i)   sa[--wv[rk[y[i]]]]=y[i];
			r[sa[0]]=0;
			for (int i=1;i<ls;++i)
				r[sa[i]]=r[sa[i-1]]+(rk[sa[i-1]]!=rk[sa[i]] || rk[j+sa[i-1]]!=rk[j+sa[i]]);
			for (int i=0;i<ls;++i)
				rk[i]=r[i];
		}
		for (int i=1;i<=n;++i)
			q.push(rk[fr[i]]);
		int ans=0;
		while (sum--){
			int v=q.top();
			q.pop();
			q.push(rk[sa[v]+1]);
			ans=(1ll*ans*365+a[sa[v]])%mo;
			//cout<<v<<' '<<sa[v]<<' '<<a[sa[v]]<<endl;
		}
		for (int i=1;i<=n;i++) q.pop();
		//cout<<ans<<endl;
		ans=1ll*ans*365%mo;
		printf("%d\n", ans);
		//cout<<ans*365%mo<<endl;
	}
    return 0;
}
