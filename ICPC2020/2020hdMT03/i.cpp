#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <tr1/unordered_map>
#define num(x) (x>='0' && x<='9')
typedef unsigned long long ull;
typedef long long ll;
using namespace std::tr1;
using namespace std;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
ll readll(){
    ll p=0, q=1;
    char ch=getchar();
    while (!num(ch))
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (num(ch)) p=p*10+ch-'0', ch=getchar();
    return p*q;
}
#define N 100005
int n, pre[N], p[N];
char s[N], ans[N];
void solve(){
	scanf("%s", s);
	strcpy(ans,s);
	n=strlen(s);
	int last=-1;
	for (int i=0;i<n;i++)
		if (s[i]=='(') pre[i]=last, last=i;
		else if (s[i]==')'){
			if (last>=0) s[last]=s[i]=0, last=pre[last];
		}
	int le=0, ri=0;
	int lr=-1, rl=n;
	for (int i=0;i<n;i++){
		p[i]=s[i]=='*';
		le+=s[i]==')';
		ri+=s[i]=='(';
		lr=s[i]==')'?i:lr;
		rl=s[i]=='('&&rl==n?i:rl;
	}
	int as=0, tle=le, tri=ri;
	for (int i=0;i<=lr;i++){
		if (s[i]=='*') as++;
		if (s[i]==')')
			if (as) as--, le--;
			else break;
	}
	as=0;
	for (int i=n-1;i>=rl;i--){
		if (s[i]=='*') as++;
		if (s[i]=='(')
			if (as) as--, ri--;
			else break;
	}
	if (le || ri) {puts("No solution!");return;}
	le=tle, ri=tri;
	for (int i=0;i<lr;i++)
		if (s[i]=='*' && le) le--, s[i]='(';
	for (int i=n-1;i>=rl;i--)
		if (s[i]=='*' && ri) ri--, s[i]=')';
	for (int i=0;i<n;i++)
		if (s[i]!='*' && p[i]) ans[i]=s[i];
	int ct=0;
	n=strlen(ans);
	for (int i=0;i<n;i++)
		if (ans[i]!='*') ans[ct++]=ans[i];
	ans[ct]=0;
	printf("%s\n",ans);
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
