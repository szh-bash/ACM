#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 50001
using namespace std;
int n, L, a[N], b[N], c[N], s[N], f[N], q[N];
long long m, d[N];
multiset <int> st;
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0',ch=getchar();
	return p;
}
bool check(long long m){
	int l=0,j=1,p=0, r=-1;
	long long sum=0;
	st.clear();
	for (int i=1;i<=n;i++){
		sum+=d[i];
		while (sum>m) sum-=d[++p];
		if (p==i) return 0;
		while (l<=r && c[q[r]]<=c[i]){
			if (l<r)st.erase(f[q[r-1]]+c[q[r]]);
			r--;
		}
		q[++r]=i;
		if (l<r) st.insert(f[q[r-1]]+c[q[r]]);
		while (q[l]<=p){
			if (l<r) st.erase(f[q[l]]+c[q[l+1]]);
			l++;
		}
		f[i]=f[p]+c[q[l]];
		if (l<r) f[i]=min(f[i],*st.begin());
	}
	return f[n]<=L;
}
int main(){
	n=read();L=read();
	for (int i=1;i<=n;i++) a[i]=read(),b[i]=read(),m+=b[i];
	for (int i=n;i;i--) s[i]=max(a[i],s[i+1]);
	int j=1,cnt=0,tmp=1;
	for (int i=1;i<=n;i++){
		if (i==j) cnt++,j++;
		while (s[j]>=b[i] && j<=n) j++;
		for (int k=tmp;k<j;k++) c[cnt]=max(c[cnt],a[k]),d[cnt]+=b[k];
		tmp=j;
	}
	long long le=0,ri=m;
	n=cnt;
	while (le<ri-1){
		long long mid=le+ri>>1;
		if (check(mid)) ri=mid;else le=mid;
	}
	cout<<ri<<endl;
	return 0;
}
