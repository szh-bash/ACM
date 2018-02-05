#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <iostream>
#include <algorithm>
#define N 20000
typedef long long ll;
using namespace std;
struct qlz{
	int n, x, flag;
}l[N];
int n, cnt, ct, q[N], flag[N], ans[N];
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9')
		(ch=='-'?q=-1:0),
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
bool cmp(qlz a, qlz b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	if (a.flag>b.flag) return 1;
	if (a.flag<b.flag) return 0;
	return a.n<b.n;
}
int main(){
	for (int T=read();T;T--){
		n=read();
		cnt=ct=0;
		int ma=0;
		for (int i=1;i<=n;i++){
			flag[i]=ans[i]=0;
			l[++cnt].n=i;l[cnt].x=read();l[cnt].flag=1;
			ma=max(ma,l[cnt].x);
			l[++cnt].n=i;l[cnt].x=read();l[cnt].flag=-1;
			ma=max(ma,l[cnt].x);
		}
		sort(l+1,l+1+cnt,cmp);
		int j=1, k=1;
		for (int time=1;time<=ma;time++){
			while (j<=cnt && l[j].x==time && l[j].flag>0){
				flag[l[j].n]=1;
				q[++ct]=l[j++].n;
			}
			while (k<=ct && flag[q[k]]<0) k++;
			if (k<=ct) ans[q[k++]]=time;
			while (j<=cnt && l[j].x==time) flag[l[j++].n]=-1;
		}
		for (int i=1;i<=n;i++) printf("%d ", ans[i]);printf("\n");
	}
	return 0;
}
