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
#define P 205
#define N 50005
struct node{
	int m, x, n;
}l[P];
bool cmp(node a, node b){ return a.x<b.x;}
unordered_map<int, int> mp;
int n, m, cnt, a[N], tg[N], f[P], dp[P][P];
int main(){
	n=read();m=read();
	for (int i=1;i<=n;i++) a[i]=read(), mp[a[i]]=i;
	a[++n]=999999999;
	tg[n]=m+1;
	for (int i=1;i<=m;i++){
		int le=read(), ri=read();
		l[++cnt].m=i;
		l[cnt].x=le;
		l[cnt].n=mp[le];
		tg[mp[le]]=i;
		tg[mp[ri]]=-i;
	}
	l[m+1].m=m+1;
	sort(l+1,l+1+m,cmp); 
	for (int i=1;i<=m;i++){
		int u=l[i].m, y=l[i].n, ri=y;
		int ma=0, flag=0, p=0, sum=0;
		for (int j=y;j<=n && ri<=n;j++){
			if (flag) sum+=a[j]-p, p=a[j];
			while (ri<=n && a[ri]-a[j]+1<=sum){
				if (tg[ri]>0) dp[u][tg[ri]]=max(ma, ri-j);
				++ri;
			}
			ma=max(ma, ri-j);
			if (tg[j]>0) flag=1, p=a[j];
			else if (tg[j]<0) flag=0;
		}
		for (;ri<=n;ri++)
			if (tg[ri]>0) dp[u][tg[ri]]=ma;
	}
	for (int i=1;i<=m+1;i++)
		for (int j=1;j<i;j++)
			f[i]=max(f[i], f[j]+dp[l[j].m][l[i].m]);
	cout<<n+f[m+1]-1<<endl;
    return 0;
}
