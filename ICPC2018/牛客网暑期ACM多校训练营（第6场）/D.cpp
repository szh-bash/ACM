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
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
ll f[N], ans;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read(), j=1;_;_--, j++){
		n=read();m=read();k=read();
		ans=0;
		for (int i=1;i<=m;i++) f[i]=0;
		for (int i=1;i<=k;i++){
			int u=read(), v=read(), w=read();
			if (!f[v] || w>f[v]) f[v]=w;
		}
		for (int i=1;i<=m;i++) ans+=f[i];
		cout<<"Case #"<<j<<": "<<ans<<endl;
	}
    return 0;
}
