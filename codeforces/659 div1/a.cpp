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
#define N 200000
int n, f[30][30];
char s[N], b[N];
void solve(){
	n=read();
	scanf("%s", s);
	scanf("%s", b);
	for (int i=0;i<20;i++)
		for (int j=0;j<20;j++) f[i][j]=0;
	for (int i=0;i<n;i++){
		if (s[i]>b[i]){
			puts("-1");
			return;
		}
		if (s[i]==b[i]) continue;
		f[s[i]-'a'][b[i]-'a']++;
	}
	int ans=0;
	for (int i=0;i<20;i++)
		for (int j=i;j<20;j++)
			if (f[i][j]){
				for (int k=j+1;k<20;k++)
					f[j][k]+=f[i][k];
				ans++;
				break;
			}
	cout<<ans<<endl;
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
