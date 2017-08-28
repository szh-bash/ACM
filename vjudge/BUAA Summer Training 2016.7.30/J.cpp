#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
	int x, y;
}a[1010], c[1010];
int n, t1;
int cmp1(zsm a, zsm b){return a.x<b.x;}
int cmp2(zsm a, zsm b){return a.x>b.x;}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d", &a[i].x), a[i].y=i, t1+=a[i].x;
	for (int i=1;i<=n;i++) scanf("%d", &c[i].x), c[i].y=i, t1-=c[i].x;
	if (t1>0){
		sort(a+1,a+1+n,cmp1);
		sort(c+1,c+1+n,cmp2);
	}
	else {
		sort(a+1,a+1+n,cmp2);
		sort(c+1,c+1+n,cmp1);
	}
	for (int i=1;i<=n;i++) cout<<a[i].y<<' '<<c[i].y<<endl;
	return 0;
}
