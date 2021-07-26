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
#define M 20000
#define N 105
int n, k, m, a[M], b[M], ans[N][2];
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
	n=read(), k=read();
	m=n*k;
	int lim=(n-1)/(k-1)+1;
	for (int i=1;i<=m;i++) a[i]=read();
	for (int i=1;i<=m;i++){
		if (ans[a[i]][0] || b[i]>=lim) continue;
		int u=a[i];
		int lst=0, mi=m;
		for (int j=1;j<=m;j++)
			if (a[j]==u && b[j]<lim){
				if (lst && j-lst<mi)
					mi=j-lst,
					ans[u][0]=lst,
					ans[u][1]=j;
				lst=j;
			} 	
			else if (b[j]>=lim) lst=0;
		for (int j=ans[u][0];j<=ans[u][1];j++) b[j]++;
		// cout<<u<<' '<<ans[u][0]<<' '<<ans[u][1]<<endl;
	}
	for (int i=1;i<=n;i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);
	return 0;
}

/*
2 3
1 2 1 2 1 2
2 3
2 1 2 1 2 1
*/
