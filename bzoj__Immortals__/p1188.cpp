#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 300000
typedef long long ll;
using namespace std;
int n, id, a[N], hash[N], f[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int sg(int x){
	if (f[x]!=-1) return f[x];
	id++;
	for (int j=x+1;j<=n;j++)
		for (int k=j;k<=n;k++)
			hash[sg(j)^sg(k)]=id;
	for (int i=0;;i++)
		if (hash[i]!=id) return f[x]=i;
}
int main(){
	for (int T=read();T;T--){
		n=read();
		for (int i=1;i<n;i++) f[i]=-1;f[n]=0;
		int flag=0, ans=0;
		for (int i=1;i<=n;i++)
			if ((a[i]=read())&1) flag^=sg(i);
		if (!flag){
			cout<<"-1 -1 -1\n0"<<endl;
			continue;
		}
		for (int i=1;i<=n;i++)
			if (a[i])
				for (int j=i+1;j<=n;j++)
					for (int k=j;k<=n;k++){
						int x=flag^sg(i)^sg(j)^sg(k);
						if (!x){
							if (!ans) cout<<i-1<<' '<<j-1<<' '<<k-1<<endl;
							ans++;
						}
					}
		cout<<ans<<endl;
	}
	return 0;
}
