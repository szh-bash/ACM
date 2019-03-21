#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 200000
typedef long long ll;
using namespace std;
int n, op[N][2], ans[N], l[N*200], flag[N];
char s[N];
int a[N], b[N], c[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	scanf("%s", s+1);
	for (int i=1;i<=n;i++) a[i]=s[i]-'0', c[i]=a[i];
	scanf("%s", s+1);
	for (int i=1;i<=n;i++) b[i]=s[i]-'0';
	for (int i=1;i<n;i++)
		ans[i]=b[i]-c[i],
		c[i+1]+=b[i]-c[i];
	if (c[n]!=b[n]){
		puts("-1");
		return 0;
	}
	int le=0, ri=0, T=100000;
	for (int i=1;i<n;i++)
		if (ans[i] && min(a[i],a[i+1])+ans[i]/abs(ans[i])>=0 && max(a[i],a[i+1])+ans[i]/abs(ans[i])<=9)
			l[++ri]=i, flag[i]=1;
	int m=n+5;
	while (le!=ri && T){
		int u=l[le==m?le=1:++le];
		flag[u]=0;
		int k=ans[u]/abs(ans[u]);
		while (ans[u] && min(a[u],a[u+1])+k>=0 && max(a[u],a[u+1])+k<=9){
			a[u]+=k;
			a[u+1]+=k;
			ans[u]-=k;
			op[T][0]=u, op[T][1]=k;
			T--;
		}
		if (u && !flag[u-1] && ans[u-1] && min(a[u],a[u-1])+ans[u-1]/abs(ans[u-1])>=0 && max(a[u],a[u-1])+ans[u-1]/abs(ans[u-1])<=9)
			l[ri==m?ri=1:++ri]=u-1, flag[u-1]=1;
		if (u<n-1 && !flag[u+1] && ans[u+1] && min(a[u+2],a[u+1])+ans[u+1]/abs(ans[u+1])>=0 && max(a[u+2],a[u+1])+ans[u+1]/abs(ans[u+1])<=9)
			l[ri==m?ri=1:++ri]=u+1, flag[u+1]=1;
	}
	if (T){
		for (int i=1;i<=n;i++)
			if (a[i]!=b[i]){
				puts("-1");
				return 0;
			}
	}
	cout<<100000-T<<endl;
	for (int i=100000;i>T;i--) printf("%d %d\n", op[i][0], op[i][1]);
	return 0;
}
