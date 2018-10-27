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
int n, flag[N], a[N];
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
	cin>>n;
	for (int i=1;i<=n;i++) a[i]=read(), flag[a[i]]=1;
	int j=1;
	for (int i=1;i<=n;i++){
		int x=read();
		if (!flag[x]){ printf("0 ");continue;}
		int p=j;
		for (;j<=n && a[j]!=x;j++);
		printf("%d ", (++j)-p);
		for (;p<j;p++) flag[a[p]]=0;
	}
	return 0;
}
