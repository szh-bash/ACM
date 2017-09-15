#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 1010
#define M 110
using namespace std;
int n, ans, m[N], a[N][M], p[N][M];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void __init(){
	n=read();
	for (int i=1;i<=n;i++)
		for (int j=m[i]=read();j;j--)
			a[i][m[i]-j+1]=read();
}
void pre(){
	ans=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<m[i];j++)
			a[i][j]-=a[i][j+1];
	for (int i=1;i<m[1];i++){
		int k=i-1;
		p[i][i]=i-1;
		for (int j=i+1;j<m[i];j++){
			while (k>=i && a[1][k+1]!=a[1][j]) k=p[i][k];
			if (a[1][k+1]==a[1][j]) ++k;
			p[i][j]=k;
		}
	}
}
void solve(){
	for (int i=1;i<m[1];i++){
		int q=M;
		for (int j=2;j<=n;j++){
			int k=i-1, q2=i-1;
			for (int w=1;w<m[j];w++){
				while (k>=i && a[1][k+1]!=a[j][w]) k=p[i][k];
				if (a[1][k+1]==a[j][w]) k++;
				q2=max(q2,k);
				if (k==m[1]-1) break;
			}
			q=min(q,q2);
		}
		ans=max(ans,q-i+2);
	}
	cout<<ans<<endl;
}
int main(){
	__init();
	pre();
	solve();
	return 0;
}
