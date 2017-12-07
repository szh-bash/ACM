#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define M 40
#define N 110000
using namespace std;
int n, ma, a[M], f[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(), ct=0, ans=0;
		while (x){
			a[++ct]=x&1;
			x/=2;
		}
		for (int j=1;j<=ct;j++)
			if (a[j] && f[j]+1>ans) ans=f[j]+1;
		for (int j=1;j<=ct;j++)
			if (a[j] && f[j]<ans) f[j]=ans;
		if (ans>ma) ma=ans;
	}
	cout<<ma<<endl;
	return 0;
}
