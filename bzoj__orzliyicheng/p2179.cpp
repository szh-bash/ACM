#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#define N 2000000
#define pi acos(-1)
using namespace std;
typedef complex<double> com;
int n, m, L, rev[N], ans[N];
com a[N], b[N];
char s[N];
void init(){
	cin>>n;
	scanf("%s", s);
	for (int i=0;i<n;i++) a[i]=s[n-i-1]-'0';
	scanf("%s", s);
	for (int i=0;i<n;i++) b[i]=s[n-i-1]-'0';
}
void fft(com *a, int flag){
	for (int i=0;i<n;i++)
		if (rev[i]<i) swap(a[i],a[rev[i]]);
	for (int j=1;j<n;j<<=1){
		com wn(cos(pi/j),flag*sin(pi/j));
		for (int i=0;i<n;i+=(j<<1)){
			com w(1,0);
			for (int k=0;k<j;k++,  w*=wn){
				com x=a[i+k], y=w*a[i+k+j];
				a[i+k]=x+y;
				a[i+k+j]=x-y;
			}
		}
	}
	if (flag<0)
		for (int i=0;i<n;i++) a[i]/=n;
}
void calc(){
	m=n<<1;
	for (n=1, L=0;n<m;n<<=1, L++);
	for (int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
	fft(a,1);
	fft(b,1);
	for (int i=0;i<n;i++) a[i]*=b[i];
	fft(a,-1);
}
void print(){
	for (int i=0;i<n;i++) ans[i]=a[i].real()+0.5;
	for (n--;n && !ans[n];n--);
	for (int i=0;i<=n;i++)
		if (ans[i]>9)
			ans[i+1]+=ans[i]/10,
			ans[i]%=10,
			(i==n?n++:0);
	for (int i=n;i>=0;i--) putchar(ans[i]+48);cout<<endl;
}
int main(){
	init();
	calc();
	print();
	return 0;
}

