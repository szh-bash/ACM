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
#define N 300005
char s[N];
int f[20];
int op[2];
void solve(){
	scanf("%s", s);
	int n=strlen(s);
	for (int i=0;i<10;i++) f[i]=0;
	for (int i=0;i<n;i++) f[s[i]-'0']++;
	int ma=2;
	for (int i=0;i<10;i++) ma=max(ma, f[i]);
	int ans=n-ma;
	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++)
			if (i!=j){
				int cnt=0;
				op[0]=i, op[1]=j;
				for (int k=0, o=0;k<n;k++)
					if ((s[k]-'0')==op[o])
						cnt++,
						o^=1;
				if (cnt&1) cnt--;
				ans=min(ans, n-cnt);
			}
	if (n==1) ans=0;
	printf("%d\n", ans);
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
