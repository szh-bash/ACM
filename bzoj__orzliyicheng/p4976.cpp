#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define INF 999999999
#define N 200100
using namespace std;
int n, k, x, ma, tot, ans, a[N], f[N];
char s[810000];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
int main(){
	fread(s,1,800000,stdin);
	n=read();k=read();
	for (int i=1;i<=n;i++){
		a[i]=read();
		ans|=a[i];
		if (a[i]>ma) ma=a[i];
	}
	int tot=log(ma)/log(2);
	if (tot+k<=n){
		cout<<ans<<endl;
		return 0;
	}
	ma=ans;
	for (int j=1;j<=ma;j++)
		f[j]=INF;
	for (int i=1;i<=n;i++)
		for (int j=ma;j>=0;j--)
			if (f[j]<INF)
				f[j|a[i]]=min(f[j]+1,f[j|a[i]]);
	for (int j=ma;j>=0;j--)
		if (f[j]<=n-k){
			cout<<j<<endl;
			break;
		}
	return 0;
}
