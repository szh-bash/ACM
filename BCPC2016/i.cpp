#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 6000000
using namespace std;
int ls, k, n, m=155;
int a[N], sa[N], rk[N], y[N], r[N], wv[N];
bool f[N];
int main(){
	freopen("1.in","r",stdin);
	freopen("1.ans","w",stdout);
	int T;
	cin>>T;
	while (T--){
		cin>>k>>n;
		ls=-1;
		getchar();
		memset(f,0,sizeof(f));
		memset(rk,0,sizeof(rk));
		memset(wv,0,sizeof(wv));
		for (int i=1;i<=n;i++){
			char ch=getchar();
			f[ls+1]=1;
			for (;int(ch)>=33 && int(ch)<=122;ch=getchar())
				a[++ls]=int(ch);
			a[++ls]=32;
		}
		for (int i=0;i<ls;i++) wv[a[i]]++;
		for (int i=1;i<m;i++) wv[i]+=wv[i-1];
		for (int i=0;i<ls;i++) sa[--wv[a[i]]]=i;
		for (int i=1;i<ls;i++) rk[sa[i]]=rk[sa[i-1]]+(a[sa[i]]!=a[sa[i-1]]);
		for (int j=1;j<ls;j*=2){
			int p=0;
			for (int i=ls-j;i<ls;i++) y[++p]=i;
			for (int i=0;i<ls;i++)
				if (sa[i]>=j) y[++p]=sa[i]-j;
			for (int i=0;i<ls;i++) wv[i]=0;
			for (int i=0;i<ls;i++) wv[rk[i]]++;
			for (int i=1;i<ls;i++) wv[i]+=wv[i-1];
			for (int i=ls;i;i--)   sa[--wv[rk[y[i]]]]=y[i];
			r[sa[0]]=0;
			for (int i=1;i<ls;i++)
				r[sa[i]]=r[sa[i-1]]+(rk[sa[i-1]]!=rk[sa[i]] || rk[j+sa[i-1]]!=rk[j+sa[i]]);
			for (int i=0;i<ls;i++)
				rk[i]=r[i];
		}
		for (int i=0;i<ls;i++)
			if (f[sa[i]]){
				if (!(--k)){
					int j=sa[i];
					while (a[j]!=32) cout<<(char)a[j++];
					cout<<endl;
					break;
				}
			}
	}
	return 0;
}
