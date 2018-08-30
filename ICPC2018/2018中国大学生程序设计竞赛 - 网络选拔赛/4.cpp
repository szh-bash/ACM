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
#define N 41000
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int f[N+5][5], x=0;
char s[1000000*30];
int read(){
    int p=0, q=1;
    while (s[x]<'0' || s[x]>'9') s[x++]=='-'?q=-1:0;
    while (s[x]>='0' && s[x]<='9') p=p*10+s[x++]-'0';
    return p*q;
}

void write(int x)
{
     if(x>9) write(x/10);
     putchar(x%10+'0');
}

int main(){
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	for (int i=3;i<N;i++){
		int x=0, y=sqrt(i)+1;
		for (int j=2;j<=y;j++)
			if (i%j==0) { x=j; break;}
		if (x) f[i][0]=x, f[i][1]=i*i/x;
		else f[i][0]=1, f[i][1]=i*i;
		int u=f[i][0]+f[i][1], v=f[i][1]-f[i][0];
		f[i][0]=v/2, f[i][1]=u/2;
	}
	fread(s,1,1000000*20,stdin);
	for (int _=read();_;_--){
		int n=read(), a=read();
		if (n>2 || !n){ puts("-1 -1"); continue;}
		if (n==1) {putchar('1'); putchar(' '); write(a+1); puts(" "); continue;}
//		printf("%d %d\n", f[a][0], f[a][1]);
		write(f[a][0]); putchar(' '); write(f[a][1]); puts("");
	}
    return 0;
}
