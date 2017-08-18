#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, T, c[200000], d[200000], q[200000], t[200000];
long long a[200000], b[200000], f[100100], g[200000];
int read(){
	char ch=getchar();
	int p=0, q=1;
	while (ch<'0' || ch>'9'){
		if (ch=='-') q=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp1(int x, int y){return a[x]>a[y];}
bool cmp2(int x, int y){return b[x]<b[y];}
int main(){
	int T;
	cin>>T;
	while (T--){
		cin>>n;
		for (int i=1;i<=n;i++) a[i]=read(), c[i]=i;
		sort(c+1,c+1+n,cmp1);
		for (int i=1;i<=n;i++) b[i]=read(), d[i]=i;
		sort(d+1,d+1+n,cmp2);
		for (int i=1;i<=n;i++)
			t[c[i]]=i;
		for (int i=1;i<=n;i++)
			c[i]=t[i];
		for (int i=1;i<=n;i++)
			t[d[i]]=i;
		for (int i=1;i<=n;i++)
			d[i]=t[i];
		for (int i=1;i<=n;i++)
			g[c[i]]=a[i],
			q[c[i]]=i;
		long long sum=n, ans=0;
		memset(f,0,sizeof(f));
		for (int i=1;i<=n;i++)
			if (!f[i]){
				int j=i;
				sum--;
				while (!f[j]){
					f[j]=1;
					j=q[d[j]];
				}
			}
		for (int i=1;i<=n;i++)
			ans+=b[i]*g[d[i]];
		cout<<ans<<' '<<sum<<endl;
	}
	return 0;
}
