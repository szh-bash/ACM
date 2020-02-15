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
#define N 200
#define M 1000
int cnt, n, nex[M], nu[M], flag[N];
int a[N][N];
char s[M];
void add(int u, int v){
	a[u][v]=1;
	u-='a'-1, v-='a'-1;
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void solve(){
	scanf("%s", s);
	if (strlen(s)==1){
		puts("YES");
		for (char x = 'a'; x<= 'z'; x++) printf("%c", x);
		puts("");
		return;
	}
	cnt = 26;
	for (int i=1;i<=26;i++){
		nex[i]=flag[i]=0;
		for (int j=1;j<=26;j++)
			a[i+'a'-1][j+'a'-1]=0;
	}
	for (int i=0;s[i];i++)
		if (i && !a[s[i-1]][s[i]]){
			add(s[i-1], s[i]);
			add(s[i],s[i-1]);
		}
	int st = -1;
	for (int i=1;i<=26;i++){
		int tot=0;
		for (int j=nex[i];j;j=nex[j]) tot++;
		if (tot>2){
			cout<<"NO"<<endl;
			return;
		}
		else if (tot==1) st = i;
	}
	if (st<0){
		puts("NO");
		return;
	}
	puts("YES");
	flag[st]=1;
	printf("%c", st+'a'-1);
	for (int p=st, pred=-1;p!=pred;){
		pred = p;
		for (int j=nex[p];j;j=nex[j])
			if (!flag[nu[j]]){
				flag[nu[j]]=1;
				printf("%c", nu[j]+'a'-1);
				p = nu[j];
			}
	}
	for (int i=1;i<=26;i++)
		if (!flag[i]) printf("%c", i+'a'-1);
	puts("");
}
int main(){
	for (int _=read();_;_--) solve();
	return 0;
}
