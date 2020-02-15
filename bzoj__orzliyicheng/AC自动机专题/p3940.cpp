#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define N 100005
#define C 26
using namespace std;
int n, cnt=1, root=1;
int go[N][C], flag[N], fail[N];
char s[N], st[N];
void init(){
	scanf("%s", st+1);
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%s", s+1);
		int len=strlen(s+1);
		for (int j=1, u=root;j<=len;j++){
			int v=s[j]-'a';
			if (!go[u][v]) go[u][v]=++cnt;
			u=go[u][v];
		}
		flag[cnt]=len;
	}
}
int l[N];
void get_fail(){
	l[1]=root;
	for (int j=0;j<C;j++) go[0][j]=root;
	for (int le=1, ri=1;le<=ri;le++){
		int u=l[le];
		for (int j=0;j<C;j++)
			if (go[u][j])
				l[++ri]=go[u][j],
				fail[go[u][j]]=go[fail[u]][j];
			else go[u][j]=go[fail[u]][j];
	}
}
int top, g[N];
void solve(){
	int len=strlen(st+1);
	g[0]=root;
	int top=1;
	for (int u=root, i=1;i<=len;i++){
		g[top]=go[u][st[i]-'a'];
		s[top]=st[i];
		top-=flag[g[top]];
		u=g[top++];
	}
	s[top]='\0';
	printf("%s\n", s+1);
}
int main(){
	init();
	get_fail();
	solve();
	return 0;
}
