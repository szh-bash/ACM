#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define mo 1000007
using namespace std;
int T, n, cnt, m;
long long x[1000], y[1000];
int nextt[1100000], nu[1100000], xx[1100000], yy[1100000];
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
				long long x2=x[j]-y1,y2=y[j]+x1, tmp=((x2*x2+y2*y2)%mo+mo)%mo;
				int k=nextt[tmp], flag=0;	
				while (nu[k]==T){
					if (xx[k]==x2 && yy[k]==y2){
						flag=1;
						break;
					}
					k=nextt[k];
				}
				if (!flag) continue;
				x2+=x1;y2+=y1;
				tmp=((x2*x2+y2*y2)%mo+mo)%mo;
				k=nextt[tmp];flag=0;
				while (nu[k]==T){
					if (xx[k]==x2 && yy[k]==y2){
						flag=1;
						break;
					}
					k=nextt[k];
				}
				if (flag) return 1;
			}
	return 0;
}
int main(){
	cin>>T;
	while (T){
		cin>>n;
		cnt=mo;
		for (int i=1;i<=n;i++){
			x[i]=read(),y[i]=read();
			int tmp=((x[i]*x[i]+y[i]*y[i])%mo+mo)%mo;
			nextt[++cnt]=nextt[tmp];
			nextt[tmp]=cnt;
			nu[cnt]=T;
			xx[cnt]=x[i];
			yy[cnt]=y[i];
		}
		int p=-1;
		if (f2()) p=4;
		cout<<p<<endl;
		T--;
	}
	return 0;
}
