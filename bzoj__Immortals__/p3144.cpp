#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 10000
#define M 50000
#define INF 1000000000
using namespace std;
int n, m ,cnt, s, t, nex[M], nu[M], va[M], w[M];
int dis[N], fl[N], fr[N], flag[N], l[N*10];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void __init(){
	
}
int main(){
	__init();
	return 0;
}
