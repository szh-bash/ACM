#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 200000
#define INF 1000000500
using namespace std;
int n, m, a[N], b[N], pia, pib, paa, pab;
long long mia, mib, maa, mab, ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	for (int T=read(), j=1;T;T--, j++){
		n=read();m=read();
		mia=mib=INF;
		maa=mab=-INF;
		//ans=(long long)INF*(-INF);
		for (int i=1;i<=n;i++){
			int x=a[i]=read();
			if (x<mia) mia=x, pia=i;
			if (x>maa) maa=x, paa=i;
		}
		for (int i=1;i<=m;i++){
			int x=b[i]=read();
			if (x<mib) mib=x, pib=i;
			if (x>mab) mab=x, pab=i;
		}
		if (maa*mab>mib*mia || maa>mia*mib)
			//pick max
			a[paa]=a[n--];
		else
			//pick min
			a[pia]=a[n--];
		mia=mib=INF;
		maa=mab=-INF;
		//ans=(long long)INF*(-INF);
		for (int i=1;i<=n;i++){
			int x=a[i];
			if (x<mia) mia=x, pia=i;
			if (x>maa) maa=x, paa=i;
		}
		for (int i=1;i<=m;i++){
			int x=b[i];
			if (x<mib) mib=x, pib=i;
			if (x>mab) mab=x, pab=i;
		}
		ans=max(mib*mia, maa*mab);
		ans=max(ans,maa);
		printf("Case #%d: %lld\n", j, ans);
	}
	return 0;
}

