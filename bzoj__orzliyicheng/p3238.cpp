#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 500100
using namespace std;
char s[N];
int h[N], q[N], r[N], rk[N], sa[N], nsa[N], p[N], l[N], vc[N], ls, m;
long long f[N], fq[N];
inline bool cmp(int x, int y, int j){
	return rk[x]!=rk[y] || rk[x+j]!=rk[y+j];
}
int main(){
	scanf("%s", s);
	ls=strlen(s);m=max(ls+1,27);
	for (int i=0;i<ls;++i) p[r[i]=(s[i]-'a')+1]++;
	for (int i=1;i<=m;++i) p[i]+=p[i-1];
	for (int i=0;i<ls;++i) sa[p[r[i]]--]=i;
	rk[sa[1]]=1;
	for (int i=2;i<=ls;++i) rk[sa[i]]=rk[sa[i-1]]+(r[sa[i-1]]!=r[sa[i]]);
	for (int j=1;j<ls && rk[sa[ls-1]]<ls;j*=2){
		int tp=0;
		for (int i=ls-j;i<ls;++i) nsa[++tp]=i; 
		for (int i=1;i<=ls;++i)
			if (sa[i]>=j) nsa[++tp]=sa[i]-j;
		for (int i=0;i<=m;++i) p[i]=0;
		for (int i=0;i<ls;++i) vc[i]=rk[nsa[i+1]];
		for (int i=0;i<ls;++i) p[rk[i]]++;
		for (int i=1;i<m;++i)  p[i]+=p[i-1];
		for (int i=ls-1;i>=0;i--) sa[p[vc[i]]--]=nsa[i+1];
		r[sa[1]]=1;
		tp=1;
		for (int i=2;i<=ls;++i) r[sa[i]]=cmp(sa[i],sa[i-1], j)?++tp:tp;
		for (int i=0;i<ls;++i)  rk[i]=r[i];
	}
	for (int i=0, m=0;i<ls;++i)
			if (rk[i]>1){
				for (int j=sa[rk[i]-1];i+m<ls && j+m<ls && s[i+m]==s[j+m];m++);
				h[--rk[i]]=m?m--:0;
			}
	for (int i=ls;i;i--) f[i]=f[i+1]+ls-sa[i];
	long long ans=0;int j=0;l[0]=ls;
	for (int i=ls-1;i;i--){
		ans+=(long long)(ls-sa[i])*(ls-i)+f[i+1];
		if (h[i]==0) {j=0;l[0]=i;continue;}
		while (j && q[j]>=h[i]) j--;q[++j]=h[i];l[j]=i;
		if (j) fq[j]=fq[j-1]+(long long)(l[j-1]-l[j])*h[i]*2;
		ans-=fq[j];
	}
	cout<<ans<<endl;
	return 0;
}
