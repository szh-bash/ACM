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
	int n=read();
	if (n%4==0){
		cout<<0<<endl;
		cout<<n/2;
		for (int i=1;i<=n/4;i++)
			printf(" %d %d", i, n-i+1);
		cout<<endl;
	}
	if (n%4==1){
		cout<<1<<endl;
		cout<<n/2+1;
		cout<<' '<<1;
		for (int i=1;i<=n/4;i++)
			printf(" %d %d", i+1, n-i+1);
		cout<<endl;
	}
	if (n%4==2){
		cout<<1<<endl;
		cout<<n/2;
		cout<<" 1";
		for (int i=1;i<=n/4;i++)
			printf(" %d %d", i+2, n-i+1);
		cout<<endl;
	}
	if (n%4==3){
		cout<<0<<endl;
		cout<<n/2+1;
		cout<<" 1 2";
		for (int i=1;i<=n/4;i++)
			printf(" %d %d", i+3, n-i+1);
		cout<<endl;
	}
	return 0;
}
