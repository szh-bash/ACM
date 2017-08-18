#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define ll long long
#define N 100100
using namespace std;
ll s[N], f[N][2];
int n, k, a[N], l[N];
int read(){
	char ch=getchar();
	int p=0;
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
double calc(int i, int j, int x){
	return (double)(f[j][x&1]-f[i][x&1]+(s[i]-s[j])*(s[i]+s[j]))/(double)(s[i]-s[j]);
}
void dp(){
	for (int p=1;p<=k;p++){
		int le=1, ri=0;
		for (int i=p+1;i<=n;i++){
			while (ri>le && calc(i-1,l[ri],p^1)<calc(l[ri-1],l[ri],p^1)) ri--;
			l[++ri]=i-1;
			while (le<ri && calc(l[le],l[le+1],p^1)<s[i]) le++;
			f[i][p&1]=f[l[le]][(p&1)^1]+(s[i]-s[l[le]])*s[l[le]];
		}
	}
	cout<<f[n][k&1]<<endl;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	n=read();k=read();int top=0;
	for (int i=1;i<=n;i++){
		a[i]=read();
		if (a[i]) a[++top]=a[i];
	}
	n=top;
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	dp();
	return 0;
}
