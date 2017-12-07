#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 999999999
#define N 200100
using namespace std;
int n, k, x, m, ans, f[N];
char s[810000];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
int main(){
	fread(s,1,500000,stdin);
	ans=n=read();k=read();m=read();
	for (int i=1;i<=m;++i) f[read()]=1;
	for (int i=2;i<=n;++i) f[i]+=f[i-1];
	for (int i=k;i<=n;++i)
		if (f[i]-f[i-k]<ans) ans=f[i]-f[i-k];
	cout<<ans<<endl;
	return 0;
}
