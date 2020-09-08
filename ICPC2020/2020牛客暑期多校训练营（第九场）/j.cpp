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
#define N 505
int n, m, ans, ct, b[N], a[N][N], pre[N][N], s[N][N], f[N*N*3];
void solve(){
	n=read();m=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=read(),
			pre[i][j]=pre[i-1][j]+a[i][j],
			s[i][j]=s[i-1][j]+(a[i][j]?1:-1);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++){
			int sum=N*N, ct=0;
			for (int k=1;k<=m;k++){
				if (pre[j][k]-pre[i-1][k]==j-i+1){
					ans+=f[sum-1]+f[sum]+f[sum+1];
					sum+=s[j][k]-s[i-1][k]-2;
					b[++ct]=sum;
					f[sum]++;
//					cout<<i<<' '<<j<<' '<<k<<' '<<sum<<endl;
				}
				else if (!a[i][k] || !a[j][k]){
					for (int p=1;p<=k;p++) f[b[p]]=0;
					sum=N*N;
					ct=0;
				}
				else sum+=s[j][k]-s[i-1][k]-2;
			}
			for (int k=1;k<=ct;k++) f[b[k]]=0;
		}
	cout<<ans<<endl;
}
int main(){
	solve();
    return 0;
}
