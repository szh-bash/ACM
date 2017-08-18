#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define  mo 1000000009
using namespace std;
int n, f[110000], b[110000], c[110000];
bool cmp(int a, int b){
	if (f[a]<f[b]) return 1;
	if (f[a]>f[b]) return 0;
	return a<b;
}
int read(){
	char ch=getchar();
	int p=0, ff=1;
	while (ch<'0' || ch>'9'){
		if (ch=='-') ff=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*ff;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int a;
		a=read();
		f[i]=f[i-1]+a;
		b[i]=i;
	}
	sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n;i++){
		int p=f[b[i]]>=0;
		for (int j=b[i];j;j-=j&(-j)) p=(p+c[j])%mo;
		for (int j=b[i];j<=n;j+=j&(-j)) c[j]=(c[j]+p)%mo;
		if (b[i]==n) {cout<<p<<endl;break;}
	}
	return 0;
}
