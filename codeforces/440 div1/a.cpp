#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int f[20];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	f[1]=f[2]=f[3]=-1;
	f[4]=1;
	f[5]=-1;
	f[6]=1;
	f[7]=-1;
	f[8]=2;
	f[9]=1;
	f[10]=2;
	f[11]=-1;
	f[12]=3;
	f[13]=2;
	f[14]=3;
	for (int T=read();T;T--){
		int n=read();
		if (n<15){
			printf("%d\n", f[n]);
		}
		else{
			int p=n/4, q=n%4;
			if (q==0 || q==2){
				printf("%d\n", p);
			}
			if (q==1){
				printf("%d\n", p-1);
			}
			if (q==3){
				printf("%d\n", p-1);
			}
		}
	}
	return 0;
}
