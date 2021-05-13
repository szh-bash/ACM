#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mo 1000000007
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
typedef double LD;
#define N 65
#define T 6005
#define eps 1e-7
int n, r, m, t[N], d[N], dt[N], res;
LD p[N];
LD f[N][T];
const LD inf = (LD)1 * 1e9* 1e5;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
LD calc(LD x){
	for (int i=0;i<N;i++)
		for (int j=0;j<T;j++)
			f[i][j]=inf;
	for (int j=res;j>=0;j--)
		f[m][j]=0;
	for (int i=m-1;i>=0;i--)
		for (int j=res;j>=0;j--)
			f[i][j]=p[i]*(f[i+1][j]+dt[i+1])+(1-p[i])*min(x, f[i+1][j+d[i]]+dt[i+1]+d[i]);
	return f[0][0]+dt[0];
}
int main(){
	n=read(), r=read(), m=read();
	for (int i=0;i<m;i++) 
		t[i]=read(), cin>>p[i], d[i]=read(), dt[i]=t[i]-(i?t[i-1]:0);
	// for (int i=0;i<m;i++)
	// 	cout<<t[i]<<' '<<p[i]<<' '<<d[i]<<endl;
	res=r-n;
	dt[m]=n-t[m-1];
	LD le=0, ri=inf;
	while (ri-le>eps){
		LD mid = (le+ri)/2;
		if (calc(mid)<mid) ri=mid;
		else le=mid;
	}
	printf("%.7lf\n", le);
	// printf("%.8Lf\n", le);
    return 0;
}
