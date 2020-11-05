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
#define N 1005
int n, m, a, b, s[N][N];
ll sum[N][N];
void solve(){
	n=read(), m=read(), a=read(), b=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			s[i][j]=read(),
			sum[i][j]=0;
			
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			ll del=s[i][j]-(sum[i][j]-sum[max(0,i-a)][j]-sum[i][max(0,j-b)]+sum[max(0,i-a)][max(0,j-b)]);
			if (j<=m-b+1 && i<=n-a+1){
				if (del<0){
					puts("QAQ");
					return;
				}
				sum[i][j]+=del;
			}
			else if (del!=0){
				puts("QAQ");
				return;
			}
		}
	
	puts("^_^");
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
