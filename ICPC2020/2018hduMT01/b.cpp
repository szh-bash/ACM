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
#define N 2000000
int n, l[N], r[N], num[N];
char s[N];
bool cmp(int a, int b){
	if (l[a]<r[a]) return l[b]<r[b]?l[a]<l[b]:1;
	if (l[a]==r[a]) return l[b]<=r[b]?0:1;
	return l[b]<=r[b]?0:r[a]>r[b];
}
void solve(){
	n=read();
	int ans=0;
	for (int i=1;i<=n;i++){
		scanf("%s", s);
		int le=0, ri=0;
		for (int j=0;s[j];j++)
			if (s[j]=='(') ri++;
			else
				if (ri) ans++, ri--;
				else le++;
		l[i]=le;
		r[i]=ri;
		num[i]=i;
	}
	sort(num+1, num+1+n, cmp);
	int sum=0;
	for (int i=1;i<=n;i++){
		int u=num[i];
		ans+=min(sum, l[u]);
		sum-=min(sum, l[u]);
		sum+=r[u];
	}
	printf("%d\n", ans*2);
}
int main(){
	for (int _=read();_;_--) solve();
    return 0;
}
