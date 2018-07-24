#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 2000000
#define mo 1000000007
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int a[N], cnt, u[N], w[N], zs[N];
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
	ll sum=2, t=2, q=0;
	a[1]=1;
	a[2]=1;
	for (int i=3;i<=10000;i++)
		sum+=a[i]=a[i-a[i-1]]+a[i-1-a[i-2]],
		a[i]!=a[i-1]?q=t:q=0,
		a[i]==a[i-1]?t++:t=1,
		q>5?zs[++cnt]=i-1,w[cnt]=a[i], u[cnt]=q:0;
		//<<q<<' '<<i<<' '<<i-a[i-1]<<' '<<i-1-a[i-2]<<' '<<a[i]<<' '<<sum<<endl;
	//cout<<sum%mo<<endl;
	for (int i=1;i<=cnt;i++) cout<<zs[i]<<' '<<u[i]<<' '<<w[i]<<endl;
    return 0;
}
