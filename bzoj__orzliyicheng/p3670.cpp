#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#define N 1010000
#define mo 1000000007
typedef long long ll;
using namespace std;
int ls, n, f[N], p[N];
char s[N];
int read(){
	int p=0;
	char ch=getchar();
	while (ch<'0' || ch>'9') ch=getchar();
	while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
	return p;
}
void pre(){
	ls=strlen(s+1);
	int j=0;
	f[1]=1;
	for (int i=2;i<=ls;i++){
		while (j && s[j+1]!=s[i]) j=p[j];
		f[i]=f[p[i]=j+=s[j+1]==s[i]]+1;
	}
}
void solve(){
	ll ans=1;
	int j=0;
	for (int i=2;i<=ls;i++){
		while (j && s[j+1]!=s[i]) j=p[j];
		if (s[j+1]==s[i]) j++;
		while ((j<<1)>i && j) j=p[j];
		ans=ans*(f[j]+1)%mo;
	}
	cout<<ans<<endl;
}
void __init(){
	for (int i=read();i;i--){
		scanf("%s", s+1);
		pre();
		solve();
	}
}
int main(){
	__init();
	return 0;
}
