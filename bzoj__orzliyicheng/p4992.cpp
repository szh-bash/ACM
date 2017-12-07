#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
struct qlz {
	int x, y, z;
}l[1000000];
int n, x, m, vis[200][200][5], a[200][200];
int d[200][200][5];
const int INF=2000000000;
char s[200000];
int read(){
	int p=0, q=1;
	while (s[x]<'0' || s[x]>'9')
		if (s[x++]=='-') q=-1;
	while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
	return p*q;
}
int main(){
	fread(s,1,100000,stdin);
	n=read();m=read();
	int b[]={-1,0,1,0}, c[]={0,1,0,-1};
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 	a[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=0;k<3;k++) d[i][j][k]=INF;
	d[1][1][0]=0;
	int le=0, ri=1;
	l[1].x=1, l[1].y=1, l[1].z=0;
	vis[1][1][0]=1;
	while (le<ri){
		le++;
		int x=l[le].x, y=l[le].y, z=l[le].z;
		vis[x][y][z]=0;
		for (int i=0;i<4;i++){
			int x2=x+b[i], y2=y+c[i], z2=z+1, w=m;
			if (!x2 || !y2 || x2>n || y2>n) continue;
			if (z2==3) w+=a[x2][y2], z2=0;
			if (d[x][y][z]+w<d[x2][y2][z2]){
				d[x2][y2][z2]=d[x][y][z]+w;
				if (!vis[x2][y2][z2]){
					ri++;
					l[ri].x=x2, l[ri].y=y2, l[ri].z=z2;
					vis[x2][y2][z2]=1;
				}
			}
		}
	}
	cout<<min(d[n][n][0],min(d[n][n][1],d[n][n][2]));
	return 0;
}
