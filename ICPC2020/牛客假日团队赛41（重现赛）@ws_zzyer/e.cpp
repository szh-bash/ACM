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
#define N 2000
#define M 1000
int n, m, k;
char s[M];
int f[N], g[N], l[N], r[N], num[N];
int get(int x){
	for (int i=1;i<=m;i++)
		if (s[i]=='L') x=l[x]; else x=r[x];
	return x;
}
int main(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++) l[i]=read(), r[i]=read();
	for (int i=1;i<=m;i++) scanf("%s", s+i);
	int st=1, ct=0, len, ed;
	for (int i=1;i<=n;i++){
		int nex=get(st);
		f[st]=nex;
		g[++ct]=st;
		num[st]=ct;
		ed=st;
		st=nex;
		if (f[st]) break;
	}
	if (k<num[ed]) printf("%d\n", g[k+1]);
	else{
		k-=num[st]-1;
		printf("%d\n", g[num[st]+k%(num[ed]-num[st]+1)]);
	}
    return 0;
}
