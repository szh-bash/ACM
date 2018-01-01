#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[200], b[200];
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
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=100;i++){
		int x=(i-1)%12+1;
		if (x==2) b[i]=28;
		else
			if (x<8 && (x&1) || x>7 && (x%2==0)) b[i]=31;
			else b[i]=30;
		//cout<<x<<' '<<b[i]<<endl;
	}
	b[38]=29;
	for (int i=1;i<=70;i++){
		int flag=1;
		for (int j=1;j<=n;j++)
			if (b[i+j-1]!=a[j]){
				flag=0;
				break;
			}
		if (flag){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
