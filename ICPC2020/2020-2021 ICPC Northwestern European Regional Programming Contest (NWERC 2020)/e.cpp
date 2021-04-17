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
#define mo 1000000007
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
#define N 5005
#define M 100005
int n, x0, y0, x1, y1;
int tag;
int cnt;
int flag[N][N];
int a[M], b[M];
struct node{
	int x, y;
}l[N*N];
bool check(int x, int y){
	return !(x<1 || x>n || y<1 || y>n || flag[x][y]==tag);
}
void ff(int t){
	int ct=cnt;
	for (int p=1;p<=ct;p++)
		for (int i=1;i<=n;i++)
			if (check(l[p].x+a[i]*t, l[p].y+b[i]*t)){
				int xx=l[p].x+a[i]*t, yy=l[p].y+b[i]*t;
				flag[xx][yy]=tag;
				l[++cnt].x=xx;
				l[cnt].y=yy;
			}
}
void print(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			printf("%d ", flag[i][j]);
		puts("");
	}
}
void baoli(){
	tag=1;
	cnt=0;
	l[++cnt].x=x0, l[cnt].y=y0;
	flag[x0][y0]=tag;
	ff(1);
	ff(1);
	// print();
	if (flag[x1][y1]==tag){
		puts("Alice wins");
		return;
	}


	tag=2;
	cnt=0;
	l[++cnt].x=x1, l[cnt].y=y1;
	flag[x1][y1]=tag;
	ff(1);
	ff(1);
	// print();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (flag[i][j]!=tag){
				printf("Tie %d %d\n", j, i);
				return;
			}
			
	puts("Bob wins");
}
#define calc(x, y) (x)*(1ll*n+1)+(y)
unordered_map <ll, int> mp;
bool scheck(int x, int y){return !(x<1 || x>n || y<1 || y>n);}
bool hit(int x0, int y0, int t){
	if (x0==x1 && y0==y1) return 1;
	++tag;
	mp[calc(x0, y0)]=tag;
	for (int i=1;i<=n;i++)
		if (scheck(x0+a[i]*t, y0+b[i]*t))
			mp[calc(x0+a[i]*t,y0+b[i]*t)]=tag;
	for (int i=1;i<=n;i++)
		if (scheck(x1-a[i]*t, y1-b[i]*t) && mp[calc(x1-a[i]*t, y1-b[i]*t)]==tag)
			return 1;
	return 0;
}
int main(){
	n=read();
	y0=read(), x0=read();
	y1=read(), x1=read();
	for (int i=1;i<=n;i++) b[i]=read(), a[i]=read();
	if (n<=5000) baoli();
	else{
		if (hit(x0,y0,1)){
			puts("Alice wins");
			return 0;
		}
		for (int i=1;i<=10000000/n;i++){
			int x=rand()*rand()%n+1, y=rand()*rand()%n+1;
			if (!hit(x,y,-1)){
				printf("Tie %d %d\n", y, x);
				return 0;
			}
		}
		puts("Bob wins");
	}
    return 0;
}
