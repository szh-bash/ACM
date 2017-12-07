#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
struct zsm{
	int x, y;
}a[30000];
bool cmp(zsm a, zsm b){return min(a.y,b.x)>min(a.x,b.y);}
int n, t1, t2;
int main(){
	scanf("%d", &n);
	for (int i=1;i<=n;i++) scanf("%d%d", &a[i].x, &a[i].y);
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		t1+=a[i].x;t2=max(t2,t1)+a[i].y;
	}
	cout<<t2<<endl;
	return 0;
}
