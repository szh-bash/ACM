#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, cnt, rk[N], wv[N], a[N], sa[N], h[N], y[N], f[N], r[N];
ll ans;
char s[N];
int main(){
	while (~scanf("%d", &n)){
		scanf("%s", s);
		int t=0, ma=0;
		for (int i=0;i<=n;i++)
			if (!i || s[i]==s[i-1]) t++;
			else{
				ma=max(ma,t);
				t=1;
			}
		//cout<<ma<<endl;
		ans=ma*3;
		cnt=n;
		for (int i=0;i<n;i++) f[i]=n-i;
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				if (i!=j)
					for (int k=0;k<3;k++)
						if (j!=k && k!=i && (i || j!=1 || k!=2)){
							f[cnt]=0;
							s[cnt++]='.';
							for (int p=0;p<n;p++)
								f[cnt]=n-p,
								s[cnt++]=s[p]=='a'?'a'+i:
										 s[p]=='b'?'a'+j:
										 		   'a'+k;
						}
		s[cnt]='\0';
		//cout<<s<<endl;
		int ls=cnt;
		int m=max(ls,200);
		for (int i=0;i<2*ls;i++) rk[i]=-1;
		for (int i=0;i<m;i++) wv[i]=0; 
		for (int i=0;i<ls;i++) a[i]=s[i];
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
		//cout<<h[0]<<' '<<s+sa[0]<<' '<<endl;
		ans+=f[sa[0]];
		for (int i=1;i<ls;i++){
			if (f[sa[i]]>min(f[sa[i-1]],h[i-1]))
				ans+=f[sa[i]]-min(f[sa[i-1]],h[i-1]);
			//cout<<h[i-1]<<' '<<f[sa[i-1]]<<' '<<f[sa[i]]<<' '<<s+sa[i]<<endl;
		}
		//cout<<ans<<endl;
		ans/=6;
		printf("%lld\n", ans);
		//for (int i=0;i<ls;i++) cout<<f[i];cout<<endl;
	}
    return 0;
}
