#include <map>
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mo 1000000007
#define mo1 1000000006
typedef long long ll;
using namespace std;
ll a[6][6], b[6][6], g[6], f1, f2, f3, c, n, ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll power(ll a, ll b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
int main(){
	scanf("%I64d%I64d%I64d%I64d%I64d", &n, &f1, &f2, &f3, &c);
	//cout<<power(c,6)*power(c,2)%mo*f3%mo*f2%mo*f1%mo*power(c,6)%mo*power(f3,2)%mo*power(f2,2)%mo*f1%mo*f3%mo<<endl;
	if (n==4){
		ans=power(c,2)*f3%mo*f2%mo*f1%mo;
	}
	else if (n==5){
		ans=power(c,6)*power(f3,2)%mo*power(f2,2)%mo*f1%mo;
	}
	else{
		n-=6;
		g[0]=2;g[1]=1;g[2]=1;g[3]=4;g[4]=14;
		a[0][0]=a[0][1]=a[0][2]=a[1][0]=a[2][1]=a[3][0]=a[3][1]=a[3][2]=a[3][3]=a[4][4]=1;
		a[4][0]=a[4][1]=a[4][2]=a[4][3]=2;
		//cout<<n<<endl;
		while (n){
			if (n&1){
				for (int i=0;i<5;i++)
					for (int j=0;j<5;j++)
						b[0][i]=(b[0][i]+g[j]*a[i][j])%mo1;
				for (int i=0;i<5;i++)
					g[i]=b[0][i],
					b[0][i]=0;
			}
			for (int i=0;i<5;i++)
				for (int j=0;j<5;j++)
					for (int k=0;k<5;k++)
						b[i][j]=(b[i][j]+a[i][k]*a[k][j])%mo1;
			for (int i=0;i<5;i++)
				for (int j=0;j<5;j++)
					a[i][j]=b[i][j],
					b[i][j]=0;
			n>>=1;
		}
		ans=1;
		ans=ans*power(c,g[4])%mo;
		ans=ans*power(f3,g[2]+g[1]+g[0])%mo*power(f2,g[1]+g[0])%mo*power(f1,g[0])%mo;
		//cout<<g[2]+g[1]+g[0]<<' '<<g[1]+g[0]<<' '<<g[0]<<endl;
		//cout<<g[4]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
