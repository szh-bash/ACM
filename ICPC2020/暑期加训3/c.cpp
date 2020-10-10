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
#define M 2000
int n, m, cnt, ans;
struct node{
	int x, y;
}l[M];
inline void add(int y, int x){
	l[++cnt].y=y;
	l[cnt].x=x;
}
inline bool cmp(node &a, node &b){ return a.x<b.x;}
void solve(){
	n=read();m=read();
	for (int i=1;i<=m;i++){
		add(+1,read());
		add(-1,read());
	}
	sort(l+1,l+1+cnt,cmp);
	int st=0, ct=0, le=n+1;
	for (int i=1, j=1;i<=cnt;i=j){
		for (;j<=cnt && l[j].x==l[i].x;j++)
			ct+=l[j].y;
		le=min(le,l[i].x);
		if (!ct) ans+=l[i].x-st+l[i].x-le, st=le, le=n+1;
	}
	ans+=n+1-st;
	cout<<ans<<endl;
}
int main(){
	solve();
    return 0;
}
