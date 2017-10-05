#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int W=1<<21;
int n, f[30], w[30];
int q[W][30];
char s[205][20000];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++) scanf("%s", s[i]);
	f[1]=2;
	for (int i=2;i<=20;i++) f[i]=f[i-1]<<1;
	for (int m=read();m;m--){
		int u=read(), v=read();
		strcpy(s[++n],s[u]);
		strcat(s[n],s[v]);
		for (int i=0;s[n][i]!='\0';i++){
			int p=0;
			for (int j=1;j<=20 && s[n][i+j-1]!='\0';j++){
				p=p*2+s[n][i+j-1]-'0';
				if (!q[p][j]) w[j]+=q[p][j]=1;
			}
		}
		for (int i=20;i>=0;i--)
			if (w[i]==f[i]){
				printf("%d\n", i);
				break;
			}
		for (int i=0;s[n][i]!='\0';i++){
			int p=0;
			for (int j=1;j<=20 && s[n][i+j-1]!='\0';j++){
				p=p*2+s[n][i+j-1]-'0';
				if (q[p][j]) q[p][j]=0, w[j]--;
			}
		}
	}
	return 0;
}
