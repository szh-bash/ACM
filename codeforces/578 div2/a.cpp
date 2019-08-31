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
#define N 500000
typedef long long ll;
using namespace std;
int n, f[10], l[100];
char s[N];
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
int main(){
	n=read();
	scanf("%s", s+1);
	for (int i=1;i<=n;i++){
		if (s[i]=='L'){
			for (int j=0;j<10;j++)
				if (!f[j]) {f[j]=1;break;}
		}
		else if (s[i]=='R'){
			for (int j=9;j>=0;j--)
				if (!f[j]) {f[j]=1;break;}
		}
		else f[s[i]-'0']=0;
	}
	for (int i=0;i<10;i++) printf("%d", f[i]);
	cout<<endl;
	return 0;
}
