#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mo 1000000007
#define N 200000
#define M 15
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k, f[N][M], nex[N][M], g[M], s[N];
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
void upd(int &p, int q){
	p=(p+q>=mo?-mo:0)+p+q;
}
int main(){
	while (~scanf("%d%d%d", &n, &m, &k)){
		for (int i=1;i<=n;i++) s[i]=read();
		for (int i=1;i<=k;i++) g[i]=0;
		for (int i=n;i>=0;i--){
			for (int j=1;j<=k;j++)
				nex[i][j]=g[j];
			for (int j=0;j<=m;j++) f[i][j]=0;
			g[s[i]]=i;
		}
		f[0][0]=1;
		for (int i=0;i<=n;i++){
			for (int j=0;j<=m && j<=i;j++)
				for (int p=1;p<=k;p++)
					if (nex[i][p] && nex[i][p]-i-1+j<=m)
						upd(f[nex[i][p]][nex[i][p]-i-1+j],f[i][j]);
		}
		int ans=0;
		for (int i=n;n-i<=m;i--)
			upd(ans,f[i][m-n+i]);
		cout<<ans<<endl;
	}
    return 0;
}
