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
int a[200000];
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
	int n=read();
	int ans=0, f[2], o=0;
	f[0]=f[1]=0;
	for (int i=1;i<=n;i++){
		a[i]=read();
		if (a[i-1]!=a[i])
			ans=max(ans,min(f[o],f[o^1])*2),
			f[o^=1]=1;
		else f[o]++;
	}	
	ans=max(ans,min(f[o],f[o^1])*2); 
	cout<<ans<<endl; 
	return 0;
}
