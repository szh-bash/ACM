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
#define N 1010
int n, k, f[N][N], mi[N], flag[N][20];
inline void add(int &a, int b){
	a+=b;
	if (a>=mo) a-=mo;
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
#define K 5*N
int cnt, nex[N+K*10];
struct node{
	int le, ri;
}l[K*10];
inline void ins(int x, int le, int ri){
	nex[++cnt]=nex[x];
	nex[x]=cnt;
	l[cnt].le=le;
	l[cnt].ri=ri;
}
inline bool check(int x, int le, int ri){
	for (int j=nex[x];j;j=nex[j]){
		int ll=l[j].le, rr=l[j].ri;
		if (ll<=le && ri<=rr) continue;
		return 0;
	}
	return 1;
}
int main(){
	n=read();k=read();cnt=n+1;
	for (int i=0;i<=n;i++) mi[i]=2010;
	for (int i=1;i<=k;i++){
		int c=read(), r=read();
		for (int j=max(0,c-r+1);j<=min(n,c+r-1);j++) ins(j+1,c-r,c+r);
		mi[c+r]=min(mi[c+r],r*2);
		flag[c+r][r]=1;
	}
	for (int i=0;i<=n;i++) f[i][i]=1;
	int inv2=power(2,mo-2);
	for (int i=n;i>=0;i--)
		for (int j=i+1;j<=n;j++){
			int sum=0;
			if (j && (mi[j]>=j-i)) add(f[i][j], f[i][j-1]), add(sum, f[i][j-1]);
			for (int k=1, p;k<=5 && j-2*k>=i;k++)
				if (check(j-2*k+1,i,j))
					if (j-2*k>i){
						if (!flag[j][k]) p=1ll*f[j-2*k][j]*inv2%mo;
						else p=f[j-2*k][j];
						add(f[i][j],1ll*f[i][j-2*k]*p%mo);
						add(sum,1ll*f[i][j-2*k]*p%mo);
					}
					else if (!flag[j][k]) add(f[i][j], sum);
		}
	cout<<f[0][n]<<endl;
    return 0;
}
/*
4 2
2 1
2 2
*/