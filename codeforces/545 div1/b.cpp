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
#define N 500005
typedef long long ll;
using namespace std;
int g[2], f[N][2], p[N];
char s[N], ss[N];
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
	scanf("%s", s+1);
	scanf("%s", ss+1);
	int l1=strlen(s+1), l2=strlen(ss+1);
	f[1][ss[1]-'0']=1;
	for (int i=2, j=0;i<=l2;i++){
		f[i][0]=f[i-1][0];
		f[i][1]=f[i-1][1];
		f[i][ss[i]-'0']++;
		while (j && ss[j+1]!=ss[i]) j=p[j];
		if (ss[j+1]==ss[i]) j++;
		p[i]=j;
	}
	for (int i=1;i<=l1;i++) g[s[i]-'0']++;
	if (f[l2][0]>g[0] || f[l2][1]>g[1]){
		printf("%s\n", s+1);
		return 0;
	}
	g[0]-=f[l2][0];
	g[1]-=f[l2][1];
	printf("%s", ss+1);
	int dx=f[l2][0]-f[p[l2]][0], dy=f[l2][1]-f[p[l2]][1], dt;
	if (dx && dy) dt=min(g[0]/dx, g[1]/dy);
	else if (dx) dt=g[0]/dx;
	else dt=g[1]/dy;
	for (int i=1;i<=dt;i++)
		for (int j=p[l2]+1;j<=l2;j++) printf("%c", ss[j]);
	g[0]-=dt*dx;
	g[1]-=dt*dy;
	for (int i=1;i<=g[0];i++) printf("0");
	for (int i=1;i<=g[1];i++) printf("1");
	puts("");
	return 0;
}
