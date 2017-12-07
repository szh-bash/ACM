#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#define pi acos(-1)
#define N 131077
using namespace std;
typedef long long ll;
typedef long double ld;
typedef complex<double> com;
int n, m, L;
com a[N], b[N];
int c[N], rev[N];
char s[100000];
void init(){
	cin>>n;
	scanf("%s", s);
	for (int i=0;i<n;i++) a[i]=s[n-1-i]-'0';
	scanf("%s", s);
	for (int i=0;i<n;i++) b[i]=s[n-1-i]-'0';
}
void get_bit(){
	for (n=1, L=0;n<m;n<<=1) L++;
}
void get_rtable(){
	for (int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
}
void mul(com *a, com*b){
	for (int i=0;i<n;i++) a[i]*=b[i];
}
void FFT(com *a, int flag){
	for (int i=0;i<n;i++)
		if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int i=1;i<n;i<<=1){
		com wn(cos(2*pi/(i*2)),flag*sin(2*pi/(i*2)));
		for (int j=0;j<n;j+=(i<<1)){
			com w(1,0);
			for (int k=0;k<i;k++, w*=wn){
				com x=a[j+k], y=w*a[j+k+i];
				//cout<<x<<' '<<y<<endl;
				a[j+k]=x+y;
				a[j+k+i]=x-y;
			}
		}
	}
	if (flag==-1) for (int i=0;i<n;i++) a[i]/=n;
}
void solve(){
	m=n<<1;
	get_bit();
	get_rtable();
	FFT(a,1), FFT(b,1);
	//for (int i=0;i<n;i++) cout<<a[i];cout<<endl;
	//for (int i=0;i<n;i++) cout<<b[i];cout<<endl;
	mul(a,b);
	FFT(a,-1);
}
void print(){
	for (int i=0;i<m;i++) c[i]=(int)(a[i].real()+0.5);
	for (;c[m-1]==0;m--);
	for (int i=0;i<m;i++){
		if (c[i]>=10){
			c[i+1]+=c[i]/10;
			c[i]%=10;
			if (i==m-1) m++;
		}
	}
	for (int i=m-1;i>=0;i--) printf("%d", c[i]);
}
int main(){
	init();
	solve();
	print();
	return 0;
}
