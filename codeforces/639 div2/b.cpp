#include <map>
#include <set> 
#include <ctime>
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
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
#define N 500000
ll f[N+5], g[N+5];
int get(int x){
	int le=0, ri=N;
	while (le<ri-1){
		int mid=le+ri>>1;
		f[mid]<=x? le=mid: ri=mid;
	}
	return f[le];
}
int solve(int x){
	int now, res=0;
	while (now=get(x)) res++, x-=now;
	return res;
}
int main(){
	for (int i=1;i<=N;i++)
		f[i]=1ll*(1+i)*i/2*3-i;
//	for (int i=1;i<=N;i++) g[i]=g[i-1]+f[i];
	for (int _=read();_;_--) printf("%d\n", solve(read()));
	return 0;
}
