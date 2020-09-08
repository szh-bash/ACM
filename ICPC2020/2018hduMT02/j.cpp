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
#define M (N*5)
int a[N], b[N], c[N];
int n;
unordered_map <int, int> mp;
bool cmp(int x, int y){return x>y;}
int sum(int x){
	int res=0;
	for (;x;x-=x&(-x)) res+=c[x];
	return res;
}
void upd(int x){
	for (;x<=n;x+=x&(-x)) c[x]++;
}
void solve(int x){
	for (int i=1;i<=n;i++) a[i]=b[i]=read(),c[i]=0;
	sort(b+1,b+1+n,cmp);
	int cnt=0;
	mp[b[1]]=cnt=1;
	for (int i=2;i<=n;i++) if (b[i]!=b[i-1]) mp[b[i]]=++cnt;
	ll ans=0;
	for (int i=1;i<=n;i++){
		int x=mp[a[i]];
		ans+=sum(x-1);
		upd(x);
	}
	printf("%I64d\n", ans*x);
}
int main(){
	int x, y;
	while (~scanf("%d%d%d", &n, &x, &y)) solve(min(x,y));
    return 0;
}
