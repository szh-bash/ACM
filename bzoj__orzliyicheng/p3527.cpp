#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#define N 400005
#define pi 3.1415926535897932384626433832795028841971
using namespace std;
typedef long double ld;
typedef long long ll;
double ans1[N],ans2[N];int n;
struct jc{
	ld a,b;
	jc operator+(const jc&x) {return (jc){a+x.a,b+x.b};}
	jc operator-(const jc&x) {return (jc){a-x.a,b-x.b};}
	jc operator*(const jc&x) {return (jc){a*x.a-b*x.b,a*x.b+b*x.a};}
} a[N],b[N],aa[N],bb[N];
inline void dft(jc *a,int fl=1) {
	for (int i=n>>1,j=1;j<n;++j) {
		if (i<j) swap(a[i],a[j]);
		int k;for (k=n>>1;i&k;i^=k,k>>=1);i^=k;
	}
	for (int m=2;m<=n;m<<=1) {
		jc wm=(jc){cos(fl*pi*2/m),sin(fl*pi*2/m)};
		for (int k=0;k<n;k+=m) {
			jc w=(jc){1,0};
			for (int j=0;j<(m>>1);j++,w=w*wm) {
				jc u=a[j+k],v=a[j+k+(m>>1)]*w;
				a[j+k]=u+v;a[j+k+(m>>1)]=u-v;
			}
		}
	}
	if (fl==-1) for (int i=0;i<n;++i) a[i].a/=n;
}
inline void fft(jc *a,jc *b) {
	dft(a);dft(b);
	for (int i=0;i<n;++i) a[i]=a[i]*b[i];
	dft(a,-1);
}
inline void Read(int &x) {x=0;char ch=getchar();while (ch>'9'||ch<'0') ch=getchar();while (ch<='9'&&ch>='0') x=x*10+ch-'0',ch=getchar();}
int main() {
	Read(n);int xx=n;
	for (int i=0;i<n;++i) cin>>a[i].a,aa[n-i-1].a=a[i].a,bb[i].a=b[i].a=1/((double)(i+1)*(i+1));
	int kd=1;while (kd<n) kd<<=1;n=kd*2;
	fft(a,b);fft(aa,bb);
	for (int i=0;i<n;++i) ans1[i+1]=(double)a[i].a;
	for (int i=0;i<n;++i) ans2[i+1]=(double)aa[i].a;
	for (int i=1;i<=xx;++i) printf("%.3lf\n",ans1[i-1]-ans2[xx-i]);
	return 0;
}
 
