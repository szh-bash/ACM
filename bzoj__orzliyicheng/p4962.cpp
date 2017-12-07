#include <cstdio>
#incldue <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int x, n, a[6000];
char s[21000];
int read(){
	int p=0;
	while (s[x]<'0' || s[x]>'9') x++;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p;
}
int main(){
	fread(s,1,20100,stdin);
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++){
		int k=i-1;
		for (int j=i+1;j<=n;j++){
			
		}
	}
	return 0;
}
