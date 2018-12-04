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
int n, k, a[200000];
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
	n=read();k=read();
	for (int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	int j=1, p=0;
	for (int i=1;i<=k;i++){
		while (j<=n && a[j]==p) j++;
		if (j>n) printf("0\n");
		else{
			printf("%d\n", a[j]-p);
			p=a[j];
		}
	}
	return 0;
}
