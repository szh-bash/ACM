#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int ls, a[3000], wv[3000], sa[3000], rk[3000], y[3000], r[3000], h[3000];
char s[3000];
int main(){
	while (scanf("%s", s)){
		ls=strlen(s);
		int m=max(ls,26);
		for (int i=0;i<2*ls;i++) rk[i]=-1;
		for (int i=0;i<m;i++) wv[i]=0; 
		for (int i=0;i<ls;i++) a[i]=s[i]-'a';
		for (int i=0;i<ls;i++) wv[a[i]]++;
		for (int i=1;i<m;i++) wv[i]+=wv[i-1];
		for (int i=0;i<ls;i++) sa[--wv[a[i]]]=i;
		rk[sa[0]]=0;
		for (int i=1;i<ls;i++) rk[sa[i]]=rk[sa[i-1]]+(a[sa[i]]!=a[sa[i-1]]);
		for (int j=1;j<ls;j*=2){
			int p=0;
			for (int i=ls-j;i<ls;i++) y[++p]=i;
			for (int i=0;i<ls;i++)
				if (sa[i]>=j) y[++p]=sa[i]-j;
			for (int i=0;i<m;i++)  wv[i]=0;
			for (int i=0;i<ls;i++) wv[rk[i]]++;
			for (int i=1;i<m;i++) wv[i]+=wv[i-1];
			for (int i=ls;i;i--)   sa[--wv[rk[y[i]]]]=y[i];
			r[sa[0]]=0;
			for (int i=1;i<ls;i++)
				r[sa[i]]=r[sa[i-1]]+(rk[sa[i-1]]!=rk[sa[i]] || rk[j+sa[i-1]]!=rk[j+sa[i]]);
			for (int i=0;i<ls;i++)
				rk[i]=r[i];
		}
		int j=0;
		for (int i=0;i<ls;i++)
		if (rk[i]<ls-1){
			for (;j+sa[rk[i]+1]<ls && j+i<ls && a[j+sa[rk[i]+1]]==a[i+j];++j);
			h[rk[i]]=j?j--:0;
		}
		for (int i=0;i<ls-1;i++) cout<<h[i]<<endl;
	}
	return 0;
}
