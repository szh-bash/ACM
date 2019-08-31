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
const double inf=999999999;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	int n=read();
	double sq=sqrt(2)-1;
	int pmina, pminb, pminc, pmind;
	int pmaxa, pmaxb, pmaxc, pmaxd;
	double mina, minb, minc, mind;
	double maxa, maxb, maxc, maxd;
	double ans=-inf;
	int p0, p1;
	mina=minb=minc=mind=inf;
	maxa=maxb=maxc=maxd=-inf;
	
	for (int i=1;i<=n;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		
		mina=min(mina,sq*u-v);if (mina==sq*u-v) pmina=i;
		maxa=max(maxa,sq*u-v);if (maxa==sq*u-v) pmaxa=i;
		
		minb=min(minb,sq*u+v);if (minb==sq*u+v) pminb=i;
		maxb=max(maxb,sq*u+v);if (maxb==sq*u+v) pmaxb=i;
		
		minc=min(minc,u-sq*v);if (minc==u-sq*v) pminc=i;
		maxc=max(maxc,u-sq*v);if (maxc==u-sq*v) pmaxc=i;
		
		mind=min(mind,u+sq*v);if (mind==u+sq*v) pmind=i;
		maxd=max(maxd,u+sq*v);if (maxd==u+sq*v) pmaxd=i;
	}
	if (maxa-mina>ans) ans=maxa-mina, p0=pmina, p1=pmaxa;
	if (maxb-minb>ans) ans=maxb-minb, p0=pminb, p1=pmaxb;
	if (maxc-minc>ans) ans=maxc-minc, p0=pminc, p1=pmaxc;
	if (maxd-mind>ans) ans=maxd-mind, p0=pmind, p1=pmaxd;
	cout<<p0<<' '<<p1<<endl;
    return 0;
}
