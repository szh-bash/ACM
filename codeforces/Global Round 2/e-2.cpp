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
#define N 500000
typedef long long ll;
using namespace std;
int n, a[N];
ll ans;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1, j=1;i<=n;i++)
		if (a[i]==1){
			j=max(i,j);
			while (j<=n && a[j]<2) j++;
			if (j<=n) a[j]-=2, ans++, a[i]--;
		}
	ll tot=0;
	for (int i=1;i<=n;i++) tot+=a[i]>1?a[i]:0;
	cout<<ans+tot/3<<endl;
	return 0;
}
