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
typedef long long ll;
using namespace std;
int n, a[500], ans;
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
	sort(a+1,a+1+n);
	int le=a[1], ri=a[1], tl=2*n, tr=2*n;
	a[tl]=a[1];
	for (int i=2;i<=n;i++){
		if (le<ri) ans=max(ans,a[i]-le), le=a[i], a[--tl]=a[i];
		else ans=max(ans,a[i]-ri), ri=a[i], a[++tr]=a[i];
	}
	ans=max(ans,(ri-le));
	for (int i=tl;i<=tr;i++) printf("%d%s", a[i], (i==tr?"\n":" "));
	return 0;
}
