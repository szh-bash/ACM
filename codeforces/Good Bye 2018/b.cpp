#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 20000
typedef long long ll;
using namespace std;
int n, x[N], y[N], a[N], b[N];
struct njh{
	int x, y;
}l[2000000];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(njh a, njh b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.y<b.y;
}
int main(){
	freopen("b_hack_0.in","w",stdout);
	cout<<1000<<endl;
	for (int i=1;i<=1000;i++) cout<<1000000-i+1<<' '<<1000000-i+1<<endl;
	for (int i=1;i<=1000;i++) cout<<2000000-i+1<<' '<<2000000-i+1<<endl;
	return 0;
	n=read();
	for (int i=1;i<=n;i++) x[i]=read(), y[i]=read();
	for (int i=1;i<=n;i++) a[i]=read(), b[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			l[(i-1)*n+j].x=x[i]+a[j],
			l[(i-1)*n+j].y=y[i]+b[j];
	sort(l+1,l+1+n*n,cmp);
	int tx=l[1].x, ty=l[1].y, cnt=1;
	for (int i=2;i<=n*n;i++)
		if (l[i].x!=l[i-1].x || l[i].y!=l[i-1].y){
			if (cnt>=n) break;
			tx=l[i].x;
			ty=l[i].y;
			cnt=1;
		}
		else cnt++;
	cout<<tx<<' '<<ty<<endl;
	return 0;
}
