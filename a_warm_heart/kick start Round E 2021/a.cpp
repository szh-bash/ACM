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
#define mo 1000000007
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
int power(ll a, int b){
	ll c=1;
	while (b){
		if (b&1) c=c*a%mo;
		a=a*a%mo;
		b>>=1;
	}
	return c;
}
#define N 20000
#define C 26
int cnt, nex[N+C], num[C], nu[N+C], p[C], q[N];
char ans[N];
char s[N];
bool cmp(int a, int b){ return p[a]>p[b];}
void add(int u, int v){
	nex[++cnt]=nex[u];nex[u]=cnt;nu[cnt]=v;
}
void solve(int o){
	scanf("%s", s);
	int n=strlen(s);
	for (int i=0;i<C;i++) p[i]=0, num[i]=i;
	for (int i=1;i<=C;i++) nex[i]=0;
	cnt = C;
	for (int i=0;i<n;i++)
		p[s[i]-'a']++,
		add(s[i]-'a'+1, i),
		ans[i]=0;
	for (int i=0;i<C;i++)
		if (p[i]>n/2){
			printf("Case #%d: IMPOSSIBLE\n", o);
			return;
		}
	sort(num,num+C,cmp);
	for (int i=1;i<C && p[num[i]];i++){
		for (int j=nex[num[i-1]+1], k=nex[num[i]+1];k;j=nex[j], k=nex[k]){
			ans[nu[j]]='a'+num[i];
		}
	}
	for (int i=0;i<n;i++)
		if (!ans[i]) ans[i]='a'+num[0];
	cnt=0;
	for (int i=0;i<n;i++)
		if (ans[i]==s[i])
			q[++cnt]=i;
	for (int i=0, j=1;i<n && j<=cnt;i++)
		if (ans[i]!='a'+num[0] && s[i]!='a'+num[0])
			swap(ans[i], ans[q[j++]]);
	ans[n]='\0';
	printf("Case #%d: %s\n", o, ans);
}
int main(){
	for (int _=read(), o=1;_;o++, _--) solve(o);
    return 0;
}
