#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
int main(){
	double ans=1000000000;
	int a, b, n;
	cin>>a>>b;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		ans=min(ans,sqrt((x-a)*(x-a)+(y-b)*(y-b))/v);
	}
	printf("%.6f\n", ans);
	return 0;
}
