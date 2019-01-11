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
struct njh{
	int x, y, n;
}l[200500];
int n, ans[200500];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(njh a, njh b) {return a.x<b.x;}
int main(){
	for (int _=read();_;_--){
		n=read();
		for (int i=1;i<=n;i++)
			l[i].x=read(),
			l[i].y=1,
			l[i].n=i,
			l[i+n].x=read(),
			l[i+n].y=-1,
			l[i+n].n=i;
		sort(l+1,l+1+n*2,cmp);
		int sum=0, tmp=0;
		for (int i=1;i<=n;i++) ans[i]=2;
		for (int i=1;i<=n*2;){
			while (i<=n*2 && l[i].x==l[i-1].x){
				tmp+=l[i].y;
				if (l[i].y<0) sum++;
				ans[l[i].n]=1;
				i++;
			}
			if (sum && !tmp) break;
			if (i<=n*2){
				tmp+=l[i].y;
				if (l[i].y<0) sum++;
				ans[l[i].n]=1;
				i++;
			}
		}
		if (sum==n){
			printf("-1\n");
		}
		else{
			for (int i=1;i<=n;i++)
				printf("%d%s", ans[i], (i==n?"\n":" "));
		}
	}
	return 0;
}
