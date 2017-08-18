#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct qlz{
	long long p, c;
}l[10000];
bool cmp(qlz a, qlz b){return a.p<b.p;}
long long n, m, F[6000], f[6000], x[6000], q[6000], s[6000];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++) scanf("%I64d", &x[i]), f[i]=(1ll)<<60;
	sort(x+1,x+1+n);
	for (int i=1;i<=m;i++)
		cin>>l[i].p>>l[i].c;
	sort(l+1,l+1+m,cmp);
	for (int i=1;i<=m;i++){
		int H=0, T=0;
		q[0]=0;
		for (int j=1;j<=n;j++){
			s[j]=s[j-1]+abs(l[i].p-x[j]);
			while (H<=T && f[q[T]]-s[q[T]]>=f[j]-s[j])
				T--;
			q[++T]=j;
			while (j-q[H]>l[i].c)
				H++;
			F[j]=f[q[H]]-s[q[H]]+s[j];
		}
		for (int j=0;j<=n;j++)
			f[j]=F[j];
	}
	printf("%I64d\n", f[n]==(1ll<<60)?-1:f[n]);
	return 0;
}
