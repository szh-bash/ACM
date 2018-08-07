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
#define INF 999999999
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
const double pi=acos(-1);
double R;
int n, m, ax, ay, bx, by;
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
	m=read();n=read();cin>>R;
	ax=read();ay=read();bx=read();by=read();
	if (ax>bx){
		swap(ax,bx);
		swap(ay,by);
	}
	int ma=max(ay,by);
	double ans=INF;
	for (int i=0;i<=ma;i++)
		ans=min(ans,abs(i-ay)*R/n+abs(i-by)*R/n+(double)i/n*R*(bx-ax)/m*pi);
	printf("%.7lf\n", ans);
    return 0;
}
