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
int n, ans[2000], l[2000], flag[2000], ct, a[2000][2000];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void solve(){
	l[1]=flag[1]=1;
	for (int le=1, ri=1;le<=ri; le++){
		int u=l[le];
		ans[++ct]=u;
		for (int j=1;j<=n;j++)
			if (a[u][j] && !flag[j]){
				flag[j]=1;
				l[++ri]=j;
			}
		//cout<<u<<' '<<l[ri]<<endl;
	}
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			a[i][j]=getchar()-48;
			if (i==j) a[i][j]=0;
		}
		getchar();
	}
/*	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) cout<<a[i][j]<<' ';
		cout<<endl;
	}*/
	solve();
	if (ct==n){
		for (int i=ct;i;i--) printf("%d ",ans[i]-1);cout<<endl;
	}
	else cout<<"impossible"<<endl;
    return 0;
}
