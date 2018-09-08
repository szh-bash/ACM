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
#include <tr1/unordered_map>
#define N 1000000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int n, cnt, nex[N], nu[N], a[N], l[N], flag[N], f[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
int main(){
	cnt=n=read();
	for (int i=1;i<n;i++){
		int u=read(), v=read();
		add(u,v);
		add(v,u);
	}
	for (int i=1;i<=n;i++) a[i]=read();
	if (a[1]!=1){
		cout<<"No"<<endl;
		return 0;
	}
	l[1]=a[1];
	flag[a[1]]=1;
	f[a[1]]=1;
	for (int le=1, ri=1;le<=ri;){
		//sort(l+le+1,l+ri+1);
		//sort(a+le+1,a+ri+1);
		int r=ri;
		for (int j=le;j<=ri;j++){
			int tr=r;
			for (int k=nex[a[j]];k;k=nex[k]){
				int v=nu[k];
				if (flag[v]) continue;
				flag[v]=1;
				l[++r]=v;
			}
			for (int k=tr+1;k<=r;k++) f[l[k]]=r;
			for (int k=tr+1;k<=r;k++)
				if (f[a[k]]!=r){
					cout<<"No"<<endl;
					return 0;
				}
		}
		le=ri+1;ri=r;
	}
	cout<<"Yes"<<endl;
    return 0;
}
