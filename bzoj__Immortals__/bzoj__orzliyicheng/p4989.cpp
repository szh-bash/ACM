#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define N 3000000
typedef long long ll;
using namespace std;
int n, x, a[N], b[N], c[N], d[N], f[N];
ll ans=1ll*999999*999999999, tmp;
char s[N];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
void solve(int a[], int b[], int t){
	for (int i=1;i<=n;i++) c[a[i]]=i;
	for (int i=1;i<=n;i++) d[i]=c[b[i]];
	ll ct=0;
	if (!t){
		for (int i=1;i<=n;i++){
			ct+=i-1;
			for (int j=d[i];j;j-=j&(-j)) ct-=f[j];
			for (int j=d[i];j<=n;j+=j&(-j)) f[j]++;
		}
		if (ct<ans) ans=ct;
		tmp=ct;
	}else ct=tmp;
	for (int i=1;i<n;i++){
		ct+=-d[i]+1+n-d[i];
		if (ct<ans) ans=ct;
	}
}
int main(){
	fread(s,1,1500000,stdin);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) b[i]=read();
	solve(a,b,0);
	solve(b,a,1);
	cout<<ans<<endl;
	return 0;
}
