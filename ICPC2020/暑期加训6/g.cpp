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
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
#define M 20005
struct node{
	int x, y, n;
}l[N+M];
bool cmp(node &a, node &b){
	if (a.x<b.x) return 1;
	if (a.x>b.x) return 0;
	return a.y<b.y;
}
#define L 101
int n, m, cnt, f[N], r[N+M], g[L+5][M];
ll sqr(int x){ return 1ll*x*x;}
void work(){
	int k=1;
	for (int i=1, j=1;i<=cnt;i=j){
		for (;k<i && l[i].x-l[k].x>100;k++)
			if (l[k].n<=n) g[l[k].x%L][l[k].y]=0;
		for (;j<=cnt && l[j].x==l[i].x;j++)
			if (l[j].n<=n) g[l[j].x%L][l[j].y]=l[j].n;
		for (j=i;j<=cnt && l[j].x==l[i].x;j++)
			if (l[j].n>n)
				for (int x=max(0,-r[l[j].n]+l[j].x);x<=l[j].x;x++){
					int h=sqrt(sqr(r[l[j].n])-sqr(l[j].x-x));
					for (int y=max(0,l[j].y-h);y<=min(l[j].y+h,10000);y++){
						f[g[x%L][y]]=0;
					}
				}
	}
	for (;k<=cnt;k++)
		if (l[k].n<=n) g[l[k].x%L][l[k].y]=0;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		int x=read(), y=read();
		l[++cnt].n=i;
		l[cnt].x=x;
		l[cnt].y=y;
	}
	sort(l+1,l+1+cnt,cmp);
	int ct=1;
	f[l[1].n]=1;
	for (int i=2;i<=cnt;i++)
		if (l[i].x==l[i-1].x && l[i].y==l[i-1].y)
			f[l[i-1].n]++, l[i].n=l[i-1].n;
		else l[++ct]=l[i], f[l[i].n]=1;
	cnt=ct;
	m=read();
	for (int i=1;i<=m;i++){
		int x=read(), y=read();
		r[i+n]=read();
		l[++cnt].n=i+n;
		l[cnt].x=x;
		l[cnt].y=y;
	}
	sort(l+1,l+1+cnt,cmp);
	work();
	for (int i=1;i<=cnt;i++) l[i].x=10000-l[i].x;
	sort(l+1,l+1+cnt,cmp);
	work();
	int ans=0;
	for (int i=1;i<=n;i++) ans+=f[i];
	cout<<ans<<endl;
    return 0;
}
/*
8
0 0
100 0
100 0
100 0
100 0
0 100
100 100
50 50
1
0 0 50
*/
