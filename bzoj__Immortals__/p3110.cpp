#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void solve(int l1, int r1, int l2, int r2){
	int mid=l2+r2>>1;
}
int main(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		l[i].type=read();
		l[i].l=read();
		l[i].r=read();
		l[i].x=read();
		q[i]=i;
	}
	solve(1,m,1,n);
	for (int i=1;i<=m;i++)
		if (l[i].type==2) printf("%d\n", ans[i]);
	return 0;
}
