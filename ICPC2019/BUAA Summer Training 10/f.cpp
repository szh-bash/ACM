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
#define N 200000
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int a[N], pre[N], nex[N], n;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int check(){
	pre[0]=nex[n+1]=1;
	a[n+1]=100005;
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]&(a[i]>=a[i-1]);
	for (int i=n;i;i--) nex[i]=nex[i+1]&(a[i+1]>=a[i]);
	for (int i=1;i<=n;i++)
		if (pre[i-1] && nex[i+1] && a[i-1]<=a[i+1]) return 1;
	return 0;
}
int main(){
	for (int _=read();_;_--){
		n=read();
		for (int i=1;i<=n;i++) a[i]=read();
		int flag=0;
		flag|=check();
		for (int i=1;i<=n/2;i++) swap(a[i], a[n-i+1]);
		flag|=check();
		printf("%s\n", flag?"YES":"NO");
	}
    return 0;
}
