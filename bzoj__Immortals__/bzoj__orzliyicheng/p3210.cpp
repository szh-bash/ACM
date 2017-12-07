#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int N=150000;
int x[N],y[N],xa,ya,n;
long long ans;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),xa+=x[i],ya+=y[i];
	xa=round((double)xa/n);
	ya=round((double)ya/n);
	for (int i=1;i<=n;i++) ans+=max(abs(xa-x[i]),abs(ya-y[i]));
	cout<<ans<<endl;
	return 0;
}
