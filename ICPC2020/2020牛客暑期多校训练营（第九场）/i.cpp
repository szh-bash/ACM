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
#define N 1000100
#define D 10
int n, b[N], f[D];
void solve(){
	n=read();
	for (int i=0;i<D;i++) f[i]=0;
	for (int i=1;i<=n;i++) f[read()]++;
	int ct=0;
	for (int i=1;i<D;i++)
		if (f[i]){
			f[i]--;
			for (int j=i;j<D;j++)
				if (f[j]){
					b[++ct]=j;
					f[j]--;
					break;
				}
			for (int j=0;j<D;j++)
				if (f[j])
				while (f[j]--){
					b[++ct]=j;
				}
			for (int j=1;j<=ct/2;j++)
				swap(b[j],b[ct-j+1]);
			int jw=0;
			for (int j=1;j<=ct;j++){
				b[j]=b[j]*i+jw;
				jw=b[j]/10;
				b[j]%=10;
			}
			while (jw){
				b[++ct]=jw%10;
				jw/=10;
			}
			break;
		}
	for (int i=ct;i;i--) printf("%d", b[i]);puts("");
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
