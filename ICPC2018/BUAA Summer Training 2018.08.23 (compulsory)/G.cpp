#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(int 
int main(){
	n=read();
	for (int i=1;i<=n;i++) g[++cnt]=f[i]=read();
	m=read();
	for (int i=1;i<=m;i++) k[i]=read(), g[++cnt]=fk[i]=read();
	sort(g+1,g+1+cnt);
	for (int i=1;i<=cnt;i++)
		if (g[i]!=g[i-1]) trans[mp[g[i]]=++ct]=g[i];
	for (int i=1;i<=n;i++){
		f[i]=mp[f[i]];
		upd(1,1,ct,f[i],1);
	}
	for (int i=1;i<=m;i++){
		upd(1,1,ct,f[k[i]],-1);
		f[k[i]]=mp[fk[i]];
		upd(1,1,ct,f[k[i]],1);
	}
    return 0;
}










