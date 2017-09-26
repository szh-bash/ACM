#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 300000
using namespace std;
int n, cnt, ans, a[N], f[N], q[N], w[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) f[a[i]=read()]++;
	for (int i=1;i<=n;i++)
		if (!f[i]) q[++cnt]=i;
	cnt=1;
	for (int i=1;i<=n;i++)
		if (f[a[i]]>1){
			if (q[cnt]<a[i] || w[a[i]]){
				f[a[i]]--;
				a[i]=q[cnt++];
				ans++;
			}
			w[a[i]]=1;
		}
	cout<<ans<<endl;
	for (int i=1;i<=n;i++) printf("%d ", a[i]);
	return 0;
}
