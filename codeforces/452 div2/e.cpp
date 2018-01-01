#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(), f[i]=a[i]==a[i-1]?f[i-1]+1:1;
	int k;
	while (k=query(1,1,n)){
		int x=get(1,1,n);
		
	}
	return 0;
}
