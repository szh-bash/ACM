#include <bits/stdc++.h>
#define mod 998244353
#define maxn 1000100
#define LL long long
using namespace std;

LL f[maxn];
int n;

int main()
{
	n=262144;
	//n=10;
	freopen("B_std.cpp","w",stdout);
	f[0]=1;
	cout<<"#include<bits/stdc++.h>\nusing namespace std;\nint n, f[300000];\nint main(){\n";
	for (int i=1;i<=n;i++) 
	{
		f[i]=f[i-1];
		for (int j=0;j<=i-1;j++) f[i]=(f[i]+f[j]*f[i-1-j])%mod;
		printf("f[%d]=%d;\n",i,f[i-1]);
	}
	cout<<"scanf(\"%d\", &n);"<<endl;
	cout<<"cout<<f[n];\nreturn 0;\n}\n"<<endl;
}
