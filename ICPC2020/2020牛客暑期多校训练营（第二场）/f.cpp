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
#define N 5005
int n, m, k;
int f[N][N], row[N][N], q[N];
ll ans;
int gcd(int x, int y){
	if (f[x][y]) return f[x][y];
	if (f[y][x]) return f[y][x];
	if (!y) return x;
	return gcd(y,x%y);
}
int main(){
	n=read();m=read();k=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j]=f[j][i]=gcd(i,j);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			f[i][j]=i*j/f[i][j];
//	for (int i=1;i<=n;i++)
//		for (int j=1;j<=m;j++) printf("%d%s", g[i][j], j==m?"\n":" ");
	for (int i=1;i<=n;i++){
		int t=0, h=1;
		for (int j=1;j<=m;j++){
			while (t>=h && f[i][q[t]]<=f[i][j]) t--;
			q[++t]=j;
			while (h<=t && q[h]<=j-k) h++;
			row[i][j]=f[i][q[h]];
		}
	}
	for (int j=k;j<=m;j++){
		int t=0, h=1;
		for (int i=1;i<=n;i++){
			while (t>=h && row[q[t]][j]<=row[i][j]) t--;
			q[++t]=i;
			while (h<=t && q[h]<=i-k) h++;
			if (i>=k) ans+=row[q[h]][j];
//			cout<<i<<' '<<j<<' '<<row[q[h]][j]<<endl;
		}
	}
	cout<<ans<<endl;
    return 0;
}
