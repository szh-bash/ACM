#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 16061105
using namespace std;
int T, n;
long long x[1000], y[1000];
int f[21000000];
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
int f2(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j){
				int x1=x[i]-x[j], y1=y[i]-y[j];
				long long x2=x[j]-y1,y2=y[j]+x1, tmp=((x2*mo+y2)%mo+mo)%mo;
				if (f[tmp]!=T) continue;
				x2+=x1;y2+=y1;
				tmp=((x2*mo+y2)%mo+mo)%mo;
				if (f[tmp]==T) return 1;
			}
	return 0;
}
int main(){
	cin>>T;
	while (T){
		cin>>n;
		for (int i=1;i<=n;i++){
			x[i]=read()+100000000,y[i]=read()+100000000;
			int tmp=((x[i]*mo+y[i])%mo+mo)%mo;
			f[tmp]=T;
		}
		int p=-1;
		if (f2()) p=4;
		cout<<p<<endl;
		T--;
	}
	return 0;
}
