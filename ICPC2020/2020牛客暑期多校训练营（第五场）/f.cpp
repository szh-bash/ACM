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
#define N 200
int n, a[N];
void print(int s, int x, int flag){
	printf("+");
	for (int i=1;i<=s;i++) printf("-");
	puts("+");
	
	printf("|");
	for (int i=1;i<=s;i++) printf("%s", (i!=s || !flag)?" ":"*");
	printf("|");
	printf("%d\n", x);
	
	printf("+");
	for (int i=1;i<=s;i++) printf("-");
	puts("+");
}
int main(){
	n=read();
	int ma=0;
	for (int i=1;i<=n;i++) a[i]=read(), ma=max(ma, a[i]);
	for (int i=1;i<=n;i++){
		int s=(1ll*50*a[i]-1)/ma+1;
		print(a[i]?s:0,a[i], a[i]==ma);
	}
    return 0;
}
