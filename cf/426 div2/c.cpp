#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int g[2000000+100], cnt, f[5];
long long zs[2000000];
long long read(){
	long long p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	int n=read();
	int N=1000000;
	g[1]=1;
	for (int i=2;i<=N;i++)
		if (!g[i]){
			zs[++cnt]=i;
			for (int j=2;j<=N/i;j++)
				g[i*j]=1;
		}
	while (n--){
		long long a=read(), b=read(), c=a;
		if (a>b) a=b, b=c;
		int ct0=0, ct1=0, flag=1;
		for (int i=1;zs[i]<1000;i++){
			if (a<N && !g[a]) break;
			if (b<N && !g[b]) break;
			if (zs[i]*zs[i]>a || zs[i]*zs[i]>b) break;
			f[0]=f[1]=0;
			if (a%zs[i]==0) ct0++;
			while (a%zs[i]==0){
				f[0]++;
				a/=zs[i];
			}
			if (b%zs[i]==0) ct1++;
			while (b%zs[i]==0){
				f[1]++;
				b/=zs[i];
			}
			if (ct0!=ct1 || (f[0]+f[1])%3){
				flag=0;
				break;
			}
			int tmp=max(f[0],f[1])-min(f[0],f[1]);
			if (f[0]>f[1]) f[0]-=tmp*2, f[1]-=tmp;
			else f[0]-=tmp, f[1]-=tmp*2;
			if (f[0]<0 || f[0]%3){
				flag=0;
				break;
			}
		}
		if (a==1 && b>1 || a>1 && b==1 || (a!=1 && b!=1 && a*a!=b && b*b!=a) || !flag)
			cout<<"no"<<endl;
		else
			cout<<"yes"<<endl;
	}
	return 0;
}
