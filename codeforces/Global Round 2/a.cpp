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
int n;
int a[500000];
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
	int head, tail;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=2;i<=n;i++) if (a[i]!=a[i-1]) {head=i;break;}
	for (int i=n-1;i;i--) if (a[i]!=a[i+1]) {tail=i;break;}
	if (a[1]!=a[n]) cout<<n-1<<endl;
	else cout<<max(max(head-1,n-head),max(n-tail,tail-1))<<endl;
	return 0;
}
