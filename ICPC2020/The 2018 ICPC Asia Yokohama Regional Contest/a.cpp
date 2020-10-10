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
#define N 2000
int n, f[N][15];
char s[N];
bool cmp(int x, int y){
	int len=min(f[x][0], f[y][0]);
	for (int i=1;i<=len;i++)
		if (f[x][i]<f[y][i]) return 1;
		else if (f[x][i]>f[y][i]) return 0;
	return f[x][0]<f[y][0];
}
void solve(){
	n=read();
	for (int i=0;i<=n;i++){
		scanf("%s", s);
		int j=0, flag=0, p=0;
		for (;s[j];j++)
			if (!(s[j]>='0' && s[j]<='9')){
				if (flag) f[i][++f[i][0]]=p, p=0, flag=0;
				f[i][++f[i][0]]=1e9+s[j];
			}
			else{
				flag=1;
				p=p*10+s[j]-'0';
			}
		if (flag) f[i][++f[i][0]]=p;
	}
	for (int i=1;i<=n;i++)
		if (cmp(i,0)) puts("-");
		else puts("+");
}
int main(){
	solve();
    return 0;
}
