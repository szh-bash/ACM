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
#define N 300000
typedef long long ll;
using namespace std;
int a[N], n, k, p;
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
	for (int _=read();_;_--){
		n=read();k=read()+1;
		for (int i=1;i<=n;i++) a[i]=read();
		double ans=999999999;
		for (int i=1;i<=n;i++)
			if (i+k<=n+1 && (a[i+k-1]-a[i])-(a[i+k-1]-a[i])/2<ans) ans=(a[i+k-1]-a[i])-(a[i+k-1]-a[i])/2, p=(double)(a[i+k-1]+a[i])/2;
		printf("%d\n", p);
	}
	return 0;
}
