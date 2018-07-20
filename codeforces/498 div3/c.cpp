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
#define N 2000000
typedef long long ll;
using namespace std;
long long n, a[N], pre[N], tai[N];
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
	for (int i=1;i<=n;i++) a[i]=read(), pre[i]=pre[i-1]+a[i];
	for (int i=n;i;i--) tai[i]=tai[i+1]+a[i];
	int i=1, j=0;
	for(;i<=n;i++)
		if (pre[i]>=tai[i+1]) break;
	if (pre[i]==tai[i+1]){
		cout<<pre[i]<<endl;
		return 0;
	}
	j=i+1;
	while (i>=1 && j<=n && pre[i]!=tai[j]){
		if (pre[i]>tai[j]) i--;
		else
			if (pre[i]<tai[j]) j++;
			else{
				cout<<pre[i]<<endl;
				return 0;
			}
	}
	if (i<1 || j>n) cout<<0<<endl;
	else cout<<pre[i]<<endl;
	return 0;
}
