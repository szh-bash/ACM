#include <map>
#include <set> 
#include <ctime>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define mo0 1050190727
#define mo1 917283913
typedef long long ll;
using namespace std;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
ll readll(){
	ll p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=='-'?q=-1:0, ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int n, m;
char s[2000000];
int f[2000000][2];
int g[2000000][2];
void add(int a[], int b[]){
	a[0]+=b[0];
	a[1]+=b[1];
	if (a[0]>=mo0) a[0]-=mo0;
	if (a[1]>=mo1) a[1]-=mo1;
//	cout<<a[0]<<' '<<a[1]<<endl;
}
int main(){
	n=read();m=read();
	int ct=0;
	f[0][0]=f[0][1]=1;
	for (int i=1;i<=n;i++){
		scanf("%s", s+(i-1)*m);
		for (int j=1;j<=m;j++, ct++)
			if (s[ct]=='#') f[ct][0]=f[ct][1]=0;
			else{
//				cout<<i<<' '<<j<<" lyksb"<<endl;
				if (j>1) add(f[ct],f[ct-1]);
				if (i>1) add(f[ct],f[ct-m]);
			}
	}
//	cout<<f[n*m-1][0]<<' '<<f[n*m-1][1]<<endl;
	
	ct--;
	g[ct][0]=g[ct][1]=1;
	for (int i=n;i;i--){
		for (int j=m;j;j--,ct--)
			if (s[ct]=='#') g[ct][0]=g[ct][1]=0;
			else{
//				cout<<i<<' '<<j<<" lyksb"<<endl;
				if (j<m) add(g[ct],g[ct+1]);
				if (i<n) add(g[ct],g[ct+m]);
			}
	}
//	for (int i=0;i<n*m;i++)
//		cout<<i<<' '<<f[i][0]<<' '<<g[i][0]<<endl;

	if (f[n*m-1][0]==1 && f[n*m-1][1]==1){
		puts("1");
		return 0;
	}
	if (f[n*m-1][0]==0 && f[n*m-1][1]==0){
		puts("0");
		return 0;
	}
	for (int i=1;i<n*m-1;i++)
		if (1ll*f[i][0]*g[i][0]%mo0==f[n*m-1][0]
				&& 1ll*f[i][1]*g[i][1]%mo1==f[n*m-1][1]){
			puts("1");
			return 0;
		}
	puts("2");
	return 0;
}
