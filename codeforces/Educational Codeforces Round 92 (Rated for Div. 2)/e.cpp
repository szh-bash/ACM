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
void solve(){
	ll m=read(), d=read(), w=read();
	ll tot=m*d;
	ll dx=d-1;
	for (int j=1;j<=cnt && zs[j]<=dx;j++)
		if (dx%zs[j]==0){
			while (dx%zs[j]==0){
				dx/=zs[j];
				if (w%zs[j]==0) w/=zs[j];
			}
		}
	
}
int main(){
	for (int i=2;i<N;i++)
		if (!flag[i]){
			zs[++cnt]=i;
			for (int j=2;j*i<N;j++)
				flag[i*j]=1;
		}
	for (int _=read();_;_--) solve();
	return 0;
}
