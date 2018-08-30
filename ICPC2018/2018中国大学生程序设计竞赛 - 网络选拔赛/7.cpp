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
#define N 40000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int ct, md, k, n, m, f[N], g[N];
ll ans, s, a[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int upd(int x){
	return x+k>=n?x+k-n:x+k;
}
int main(){
	for (int _=read(), T=1;_;_--,T++){
		ans=0;
		n=read();cin>>s;m=read();k=read();
		for (int i=0;i<n;i++) a[i]=read(), f[i]=0;
		for (int i=0;i<n;i++)
			if (!f[i]){
				int j=upd(i);
				ll x=a[i], tp;
				f[i]=1;
				g[ct=1]=i;
				//cout<<i;
				while (j!=i){
				//	cout<<' '<<j;
					x+=a[j];
					g[++ct]=j;
					f[j]=1;
					j=upd(j);
				}
			//	cout<<endl;
				if (x>0){
					tp=(ll)m/ct*x, md=m%ct;
					ll y=0, ma=0;
					int p=0;
					for (j=1;j<=ct+md;j++){
						y+=a[j>ct?g[j-ct]:g[j]];
						if (j-p>md){
							while ((y-=a[++p>ct?g[p-ct]:g[p]])<0);
							while (p<j && a[p+1>ct?g[p+1-ct]:g[p+1]]<0) y-=a[++p>ct?g[p-ct]:g[p]];
						}
						if (y>0) ma=max(ma,y);else y=0, p=j;
					}
					ans=max(ans,tp+ma);
					if (m>ct){
						tp=(ll)m/ct*x-x, md=ct;
						y=0, ma=0;
						p=0;
						for (j=1;j<=ct+md;j++){
							y+=a[j>ct?g[j-ct]:g[j]];
							if (j-p>md){
								while ((y-=a[++p>ct?g[p-ct]:g[p]])<0);
								while (p<j && a[p+1>ct?g[p+1-ct]:g[p+1]]<0) y-=a[++p>ct?g[p-ct]:g[p]];
							}
							if (y>0) ma=max(ma,y);else y=0, p=j;
						}
						ans=max(ans,tp+ma);
					}
				}
				tp=0, md=min(m,ct);
				ll y=0, ma=0;
				int p=0;
				for (j=1;j<=ct+md;j++){
					y+=a[j>ct?g[j-ct]:g[j]];
					if (j-p>md){
						while ((y-=a[++p>ct?g[p-ct]:g[p]])<0);
						while (p<j && a[p+1>ct?g[p+1-ct]:g[p+1]]<0) y-=a[++p>ct?g[p-ct]:g[p]];
					}
					if (y>0) ma=max(ma,y);else y=0, p=j;
				}
				ans=max(ans,tp+ma);
			}
		printf("Case #%d: %lld\n", T, s-ans<0?0:s-ans);
	}
    return 0;
}
