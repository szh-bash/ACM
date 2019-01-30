#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int a[5205][5205], f[5205][5205];
char s[10000];
int n, m;
int read(){
	int p=0, q=1;
	char ch=getchar();
	while (ch<'0' || ch>'9') 
		ch=='-'?q=-1:0,
		ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p*q;
}
int main(){
	n=read();
	m=n/4;
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		for (int j=0;j<m;j++){
			int x=0;
			if (s[j]>'9'){
				x=s[j]-'A'+10;
			}
			else x=s[j]-'0';
			int k=j*4+4;
			while (x){
				a[i][k--]=x&1;
				x>>=1;
			}
		}
		for (int j=1;j<=n;j++)
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
	}
	int ans=1;
	for (int x=n;x>1;x--){
		if (n%x) continue; 
		int flag=0;
		for (int i=1;i<=n;i+=x)
			for (int j=1;j<=n;j+=x){
				int ti=i+x>n?n:i+x-1, tj=j+x>n?n:j+x-1;
				if (f[ti][tj]-f[ti][j-1]-f[i-1][tj]+f[i-1][j-1]!=(ti-i+1)*(tj-j+1) && f[ti][tj]-f[ti][j-1]-f[i-1][tj]+f[i-1][j-1]!=0){
					flag=1;
					break;
				}
			}
		if (flag) continue;
		ans=x;
		break; 
	}
	cout<<ans<<endl;
	return 0;
}
