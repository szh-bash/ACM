#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 3000
using namespace std;
int n, M, f[200][N], ans0, ans, num[N], t[N], d[N], p[N], cnt, w[N], q[200][N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') (ch=='-'?q=-1:0), ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) num[i]=i, t[i]=read(), d[i]=read(), p[i]=read(), M=max(M,d[i]);
	for (int i=1;i<=n;i++)	
		for (int j=i+1;j<=n;j++)
			if (d[i]>d[j])
				swap(t[i],t[j]),
				swap(d[i],d[j]),
				swap(p[i],p[j]),
				swap(num[i],num[j]);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=M;j++){
			if (t[i]+j<d[i]){
				if (f[i-1][j]+p[i]>f[i-1][j+t[i]])
					q[i][j+t[i]]=1;
				f[i][j+t[i]]=max(f[i-1][j+t[i]],f[i-1][j]+p[i]);
			}
			if (f[i-1][j]>f[i][j]) q[i][j]=0;
			f[i][j]=max(f[i][j],f[i-1][j]);
		}
	for (int j=0;j<=M;j++)
		if (f[n][j]>ans) ans=f[n][j], ans0=j;
	cout<<ans<<endl;
	for (int i=n;i;i--){
		if (q[i][ans0]) w[++cnt]=i, ans0-=t[i];
	}
	cout<<cnt<<endl;
	for (int i=cnt;i;i--) printf("%d ", num[w[i]]);
	return 0;
}
